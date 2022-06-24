//
// Created by pauls on 19/06/2022.
//

#include "While.h"
#include <sstream>

void WhileStatement::renderX86(ostream &o) const {
    o << "    jmp      .L" << compareLabel << endl;

    o << ".L" << contentLabel << ":" << endl;
    content->renderX86(o);

    o << ".L" << compareLabel << ":" << endl;
    compare->renderX86(o);
    o << "    cmpl    $0, " << compare->offset << "(%rbp)" << endl;
    o << "    jne      .L" << contentLabel << endl;
}

void WhileStatement::affect(IrScope *owner) {
    setOwner(owner);
    compare->affect(owner);
    content->setOwner(owner);
    content->affect(owner);
    compareLabel = owner->getNewLabel();
    contentLabel = owner->getNewLabel();
}

WhileStatement::WhileStatement(Expression *compare, Instruction *content)
        : Expression(), compare(compare), content(content) {

}
