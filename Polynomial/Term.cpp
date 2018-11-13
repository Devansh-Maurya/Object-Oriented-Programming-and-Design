//
// Created by devansh on 5/11/18.
//

class Term {

public:

    int exp;
    int coff;

    Term(int exp, int coff) : exp(exp), coff(coff) {}

    Term() {
        exp = 0;
        coff = 0;
    }

    Term(const Term& term) {
        exp = term.exp;
        coff = term.coff;
    }
};
