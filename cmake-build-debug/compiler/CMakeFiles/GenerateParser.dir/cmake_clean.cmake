file(REMOVE_RECURSE
  "../../compiler/generated/ifccBaseListener.cpp"
  "../../compiler/generated/ifccBaseVisitor.cpp"
  "../../compiler/generated/ifccLexer.cpp"
  "../../compiler/generated/ifccListener.cpp"
  "../../compiler/generated/ifccParser.cpp"
  "../../compiler/generated/ifccVisitor.cpp"
  "CMakeFiles/GenerateParser"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/GenerateParser.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
