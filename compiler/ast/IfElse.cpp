//
// Created by pauls on 17/06/2022.
//

#include "IfElse.h"
#include <sstream>

void IfStatement::renderX86(ostream &o) const {
    compare->renderX86(o);
    o << "    cmpl    $0, " << compare->offset << "(%rbp)" << endl;
    int nextLabel;
    if (elseStatement != nullptr) nextLabel = elseStatement->label;
    else nextLabel = finalLabel;
    o << "    je      .L" << nextLabel << endl;

    content->renderX86(o);

    if (elseStatement != nullptr) {
        o << "    jmp      .L" << finalLabel << endl;
        elseStatement->renderX86(o);
    }

    // Closing the branch
    if (finalLabel == firstLabel + 1) {
        o << ".L" << finalLabel << ":" << endl;
    }
}

void IfStatement::affect(IrScope *owner) {
    setOwner(owner);
    compare->affect(owner);
    firstLabel = owner->getNewLabel();
    if (finalLabel == 0) finalLabel = owner->getNewLabel();
    content->setOwner(owner);
    content->affect(owner);
    if (elseStatement != nullptr) {
        elseStatement->finalLabel = finalLabel;
        elseStatement->affect(owner);
    }
}

IfStatement::IfStatement(Expression *compare, Instruction *content,
                         ElseStatement *elseStatement) :
        Expression(), compare(compare), content(content),
        elseStatement(elseStatement) {
}

void ElseStatement::affect(IrScope *owner) {
    if (dynamic_cast<IfStatement *>(content) != nullptr) {
        ((IfStatement *) content)->finalLabel = finalLabel;
    }
    setOwner(owner);
    label = owner->getNewLabel();
    content->setOwner(owner);
    content->affect(owner);
}

ElseStatement::ElseStatement(Instruction *content)
        : Expression(), content(content) {

}

void ElseStatement::renderX86(ostream &o) const {
    o << ".L" << label << ":" << endl;
    content->renderX86(o);
}