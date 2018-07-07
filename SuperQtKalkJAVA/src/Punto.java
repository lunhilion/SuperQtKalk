import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class Punto {
    private double x;
    private double y;

    public Punto(double i, double j) {
        x = i;
        y = j;
    }

    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }

    public void setPunto(Punto p) {
        x = p.getX();
        y = p.getY();
    }

    public void setX(double i) {
        x = i;
    }

    public void setY(double i) {
        y = i;
    }

    public double distanza(Punto p) {
        double a = pow(p.getX()-x,2);
        double b = pow(p.getY()-y,2);
        return sqrt(a+b);
    }

    static double distanzaDuePunti(Punto a, Punto b) {
        double v = pow(b.getX() - a.getX(), 2);
        double z = pow(b.getY() - a.getY(), 2);
        double dist = sqrt(v+z);
        return dist;
    }
}
