#ifndef KALKEXCEPTION_H
#define KALKEXCEPTION_H
#include <QString>

class KalkException {
private:
    QString error;
public:
    KalkException(QString = "Errore sconosciuto");
    void printError() const;
};

class TypeErr : public KalkException {
public:
    TypeErr(QString = "Errore di tipo");
};

class UndefValue : public KalkException {
public:
    UndefValue(QString = "Valore non definito");
};

class EmptyObj : public KalkException {
public:
    EmptyObj(QString = "Oggetto non presente");
};

class OperatErr : public KalkException {
public:
    OperatErr(QString = "Errore operazione");
};

class EmptyPoly : public EmptyObj {
public:
    EmptyPoly(QString = "Poligono non implementato");
};

class ViewUndefValue : public UndefValue {
public:
    ViewUndefValue(QString = "Valore non definito nella View");
};

#endif // KALKEXCEPTION_H
