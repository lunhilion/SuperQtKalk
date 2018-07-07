import java.util.ArrayList;
import static java.lang.Math.sqrt;

public class Triangolo extends LatiFiniti {

    public Triangolo(Punto a, Punto b, Punto c) {
        super(new ArrayList<Punto>());
        pushVertice(a);
        pushVertice(b);
        pushVertice(c);
    }

    public double getArea() {
        double semiP = getPerimetro()/2;
        ArrayList<Double> l = getLati();
        double area = sqrt(semiP * (semiP-l.get(0)) * (semiP-l.get(1)) * (semiP-l.get(2)));
        return area;
    }
    

    public double getAltezza() {
        return getArea()/getLato(1);
    }
}
