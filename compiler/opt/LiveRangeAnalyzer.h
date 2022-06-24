//
// Created by pauls on 22/06/2022.
//

#ifndef LIBANTLR4_LIVERANGEANALYZER_H
#define LIBANTLR4_LIVERANGEANALYZER_H


#include "../ir/Prog.h"
#include "../ir/Declaration.h"
#include "../ir/IfElse.h"
#include "../ir/While.h"

using namespace std;

class LiveRangeAnalyzer {
public:
    explicit LiveRangeAnalyzer(Function *f) : f(f) {
        this->blockSizes = new unordered_map<Block *, int>();
        this->size = computeBlockSize(f);
        this->in = new vector<set<string> *>(this->size);
        this->out = new vector<set<string> *>(this->size);
        this->def = new vector<set<string> *>(this->size);
        this->use = new vector<set<string> *>(this->size);
        fillWithEmptySet(in);
        fillWithEmptySet(out);
    }

    void launch() {
        int k = 0;
        init(f, &k);
        while (change) {
            change = false;
            compute(f, size - 1, -1, -1);
        }

    }

private:
    Function *f;
    int size;
    vector<set<string> *> *in;
    vector<set<string> *> *out;
    vector<set<string> *> *def;
    vector<set<string> *> *use;
    unordered_map<Block *, int> *blockSizes;
    bool change = true;

    int compute(IrInstruction *inst, int i, int s0, int s1) {
        int j = i;
        if (dynamic_cast<Block *>(inst) != nullptr) {
            bool first = true;
            for (int k = (int) ((Block *) inst)->instructions.size() - 1;
                 k >= 0; --k) {
                if (first) {
                    first = false;
                    j = compute(((Block *) inst)->instructions[k], j, s0, s1);
                } else {
                    j = compute(((Block *) inst)->instructions[k], j, j + 1,
                                -1);
                }
            }
        } else if (dynamic_cast<IfStatement *>(inst) != nullptr) {
            auto *ifStatement = (IfStatement *) inst;
            //TODO IMPROVE
            /*j = compute(ifStatement->elseStatement, j, );
            j = compute(ifStatement->content, j, j - blockSizes->at((Block *) ifStatement->content), );
            j = compute(ifStatement->compare, j, j+1, j - blockSizes->at((Block *) ifStatement->content));*/
        } else if (dynamic_cast<ElseStatement *>(inst) != nullptr) {
            auto *elseStatement = (ElseStatement *) inst;
            //TODO IMPROVE
            //j = compute(elseStatement->content, j, s0, s1);
        } else if (dynamic_cast<WhileStatement *>(inst) != nullptr) {
            auto *whileStatement = (WhileStatement *) inst;
            j = compute(whileStatement->content, j, j - blockSizes->at((Block *) whileStatement->content), -1);
            j = compute(whileStatement->compare, j, j + 1, s0);
        } else {
            if (s0 >= 0) {
                for (const auto &s: *(*in)[s0]) {
                    if ((*out)[j]->find(s) == (*out)[j]->end()) {
                        (*out)[j]->insert(s);
                        change = true;
                    }
                }
            }
            if (s1 >= 0) {
                for (const auto &s: *(*in)[s1]) {
                    if ((*out)[j]->find(s) == (*out)[j]->end()) {
                        (*out)[j]->insert(s);
                        change = true;
                    }
                }
            }
            for (const auto &d: *(*use)[j]) {
                (*in)[j]->insert(d);
            }
            for (const auto &s: *(*out)[j]) {
                if ((*def)[j]->find(s) == (*def)[j]->end()) {
                    (*in)[j]->erase(s);
                }
            }
            j--;
        }
        return j;
    }


    int computeBlockSize(IrInstruction *i) {
        int c = 0;
        if (dynamic_cast<Block *>(i) != nullptr) {
            for (auto *inst: ((Block *) i)->instructions) {
                c += computeBlockSize(inst);
            }
            blockSizes->insert({((Block *) i), c});
            return c;
        } else if (dynamic_cast<BlockWrapper *>(i)) {
            if (dynamic_cast<IfStatement *>(i) != nullptr) {
                auto *ifStatement = (IfStatement *) i;
                c += computeBlockSize(ifStatement->compare);
                c += computeBlockSize(ifStatement->content);
                c += computeBlockSize(ifStatement->elseStatement);
            } else if (dynamic_cast<WhileStatement *>(i) != nullptr) {
                auto *whileStatement = (WhileStatement *) i;
                c += computeBlockSize(whileStatement->compare);
                c += computeBlockSize(whileStatement->content);
            } else if (dynamic_cast<ElseStatement *>(i) != nullptr) {
                auto *elseStatement = (ElseStatement *) i;
                c += computeBlockSize(elseStatement->content);
            }
            return c;
        } else {
            return 1;
        }
    }


    void init(IrInstruction *i, int *k) {
        if (dynamic_cast<Block *>(i) != nullptr) {
            for (auto *inst: ((Block *) i)->instructions) {
                init(inst, k);
            }
        } else if (dynamic_cast<BlockWrapper *>(i)) {
            if (dynamic_cast<IfStatement *>(i) != nullptr) {
                auto *ifStatement = (IfStatement *) i;
                init(ifStatement->compare, k);
                init(ifStatement->content, k);
                init(ifStatement->elseStatement, k);
            } else if (dynamic_cast<WhileStatement *>(i) != nullptr) {
                auto *whileStatement = (WhileStatement *) i;
                init(whileStatement->compare, k);
                init(whileStatement->content, k);
            } else if (dynamic_cast<ElseStatement *>(i) != nullptr) {
                auto *elseStatement = (ElseStatement *) i;
                init(elseStatement->content, k);
            }
        } else {
            (*def)[*k] = new set<string>();
            auto si = *i->def();
            for (auto *d: si) {
                (*def)[*k]->insert(*d);
            }
            (*use)[*k] = new set<string>();
            for (auto *d: *i->use()) {
                (*use)[*k]->insert(*d);
            }
            (*k) = *k + 1;
        }
    }

    void fillWithEmptySet(vector<set<string> *> *v) {
        for (auto &i: *v) {
            i = new set<string>();
        }
    }
};


#endif //LIBANTLR4_LIVERANGEANALYZER_H
