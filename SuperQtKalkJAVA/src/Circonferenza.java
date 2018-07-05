public class Circonferenza implements Poligono {
    private Punto centro;
    private double raggio;
    public static double PI = 3.14159265359; //rivedere anche in c++

    public Circonferenza(Punto p, int i) {
        centro = p;
        raggio = i;
    }

    public double getArea() {
        double a = raggio * raggio * PI;
        return a;
    }

    public double getPerimetro() {
        double p = 2 * raggio * PI;
        return p;
    }

    public Punto getBaricentro() {
        return centro;
    }

    public double getRaggio() {
        return raggio;
    }
 }
