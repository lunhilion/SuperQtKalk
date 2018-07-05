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

#endif // KALKEXCEPTION_H
