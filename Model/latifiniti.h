#ifndef LATIFINITI_H
#define LATIFINITI_H


class LatiFiniti : public Poligono {
private:
  Qvector<const Punto*> vertici;    //vector costante o no?
public:
  LatiFiniti(const Qvector<const Punto*>&); //controllare cosa si può chiamare da sotto
  virtual void rotate(unsigned int);
  void move(const Punto&);

  double getPerimetro() const;
  Punto getBaricentro() const;
  virtual ~LatiFiniti();
  double getLato(unsigned int) const;
  Qvector<double> getLati() const;
  Punto getVertice(unsigned int) const;
  void setVertice(unsigned int, const Punto&) const;
};

//qui implementiamo tutto meno che il getArea. Quindi questa classe è virtuale

#endif // LATIFINITI_H
