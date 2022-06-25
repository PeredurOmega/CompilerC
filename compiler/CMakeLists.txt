# -*- mode:cmake -*-
if (NOT UNIX)
    message(WARNING "Unsupported operating system")
endif ()

set(compiler-GENERATED_SRC
        ${PROJECT_SOURCE_DIR}/compiler/generated/ifccBaseListener.cpp
        ${PROJECT_SOURCE_DIR}/compiler/generated/ifccBaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/compiler/generated/ifccLexer.cpp
        ${PROJECT_SOURCE_DIR}/compiler/generated/ifccListener.cpp
        ${PROJECT_SOURCE_DIR}/compiler/generated/ifccParser.cpp
        ${PROJECT_SOURCE_DIR}/compiler/generated/ifccVisitor.cpp
        )

set(compiler-IR_SRC
        ${PROJECT_SOURCE_DIR}/compiler/ast/Prog.cpp
        ir/IrElement.cpp ir/IrElement.h ast/Function.cpp ast/Function.h ast/IrScope.cpp ast/IrScope.h ast/Block.cpp ast/Block.h ast/TypeSymbol.cpp ast/TypeSymbol.h ast/Instruction.cpp ast/Instruction.h ast/Declaration.cpp ast/Declaration.h ast/Expression.cpp ast/Expression.h ast/OpExpression.cpp ast/OpExpression.h ast/IfElse.cpp ast/IfElse.h ast/UnaryOp.cpp ast/UnaryOp.h ast/While.cpp ast/While.h ir/IrInstruction.cpp ir/IrInstruction.h ir/BasicBlock.cpp ir/BasicBlock.h ir/IrConstant.cpp ir/IrConstant.h ir/OpIrInstruction.cpp ir/OpIrInstruction.h ir/UnaryOpIrInstruction.cpp ir/UnaryOpIrInstruction.h ir/IrReturn.cpp ir/IrReturn.h ir/IrJump.cpp ir/IrJump.h ir/IrCopy.cpp ir/IrCopy.h ir/IrPushq.cpp ir/IrPushq.h ir/IrCall.cpp ir/IrCall.h ir/IrAddQ.cpp ir/IrAddQ.h ir/IrLabel.cpp ir/IrLabel.h ir/IrPrologue.cpp ir/IrPrologue.h ir/IrNoOp.cpp ir/IrNoOp.h ir/IrEpilogue.cpp ir/IrEpilogue.h ir/IrCompare.cpp ir/IrCompare.h ir/IrGlobal.cpp ir/IrGlobal.h ir/IrMovzbl.cpp ir/IrMovzbl.h)

foreach (src_file ${compiler-GENERATED_SRC})
    set_source_files_properties(
            ${src_file}
            PROPERTIES
            GENERATED TRUE
    )
endforeach (src_file ${compiler-GENERATED_SRC})

add_custom_target(GenerateParser DEPENDS ${compiler-GENERATED_SRC})
add_custom_command(OUTPUT ${compiler-GENERATED_SRC}
        COMMAND
        ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/compiler/generated/
        COMMAND
        "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -visitor -o ${PROJECT_SOURCE_DIR}/compiler/generated/ -package antlrcpptest ${PROJECT_SOURCE_DIR}/compiler/ifcc.g4
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        DEPENDS ${PROJECT_SOURCE_DIR}/compiler/ifcc.g4
        )

include_directories(
        ${PROJECT_SOURCE_DIR}/runtime/src
        ${PROJECT_SOURCE_DIR}/runtime/src/misc
        ${PROJECT_SOURCE_DIR}/runtime/src/atn
        ${PROJECT_SOURCE_DIR}/runtime/src/dfa
        ${PROJECT_SOURCE_DIR}/runtime/src/tree
        ${PROJECT_SOURCE_DIR}/runtime/src/support
        ${PROJECT_SOURCE_DIR}/compiler/generated
)

#file(GLOB compiler_SRC "${PROJECT_SOURCE_DIR}/compiler/generated/*")
set(compiler_SRC ${PROJECT_SOURCE_DIR}/compiler/main.cpp ${PROJECT_SOURCE_DIR}/compiler/CodeGenVisitor.cpp ${compiler-GENERATED_SRC} ${compiler-IR_SRC})

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(flags_1 "-Wno-overloaded-virtual")
else ()
    set(flags_1 "-MP /wd4251")
endif ()

foreach (src_file ${compiler_SRC})
    set_source_files_properties(
            ${src_file}
            PROPERTIES
            COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
    )
endforeach (src_file ${compiler_SRC})

add_executable(compiler ${compiler_SRC})
#add_precompiled_header(compiler ${PROJECT_SOURCE_DIR}/runtime/src/antlrcpp-Prefix.h)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(compiler PRIVATE "/MT$<$<CONFIG:Debug>:d>")
endif ()

find_package(Threads)

target_link_libraries(compiler antlr4_static ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS compiler
        DESTINATION "share"
        COMPONENT dev
        )