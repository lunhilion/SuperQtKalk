#ifndef RGB_H
#define RGB_H


class Rgb : public Colore {
    private:
        unsigned int red;
        unsigned int green;
        unsigned int blue;
        static unsigned int RGB_MAX_VALUE; //da inizializzare fuori
    public:
        Rgb(unsigned int=0, unsigned int=0, unsigned int=0);
        unsigned int getRed() const;
        unsigned int getGreen() const;
        unsigned int getBlue() const;
        void setRed(unsigned int);		//faranno i controlli sul MAX_VALUE
        void setGreen(unsigned int);
        void setBlue(unsigned int);
        Rgb& operator+ (const Colore&) const;
        Rgb& operator- (const Colore&) const;
        QString getHex() const;
        Rgb media(const Colore&) const;
};

#endif // RGB_H
