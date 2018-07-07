public class Use {

    public static void main(String[] args) {
    	
    	//Punto
    	Punto a = new Punto(5,5);
    	Punto b = new Punto(5,7);
    	System.out.println("Distanza tra due punti: ");
    	System.out.println(Punto.distanzaDuePunti(a, b));
    	
    	//Triangolo
    	Poligono p1 = new Triangolo(new Punto(3,3), new Punto(7,3), new Punto(5,7));
    	System.out.println("Perimetro Triangolo: ");
    	System.out.println(p1.getPerimetro());
    	System.out.println("Area Triangolo: ");
    	System.out.println(p1.getArea());
    	System.out.println("Baricentro Triangolo: ");
    	System.out.println("X: " + p1.getBaricentro().getX() + " Y: " + p1.getBaricentro().getY());
    	
    	//Quadrilatero
    	Poligono p2 = new Quadrilatero(new Punto(3,3), new Punto(7,3), new Punto(7,6), new Punto(3,6));
    	System.out.println("Perimetro Quadrilatero: ");
    	System.out.println(p2.getPerimetro());
    	System.out.println("Area Quadrilatero: ");
    	System.out.println(p2.getArea());
    	System.out.println("Baricentro Quadrilatero: ");
    	System.out.println("X: " + p2.getBaricentro().getX() + " Y: " + p2.getBaricentro().getY());
    	
    	//Circonferenza
    	Poligono p3 = new Circonferenza(new Punto(5,5), 3);
    	System.out.println("Perimetro Circonferenza: ");
    	System.out.println(p3.getPerimetro());
    	System.out.println("Area Circonferenza: ");
    	System.out.println(p3.getArea());
    	System.out.println("Baricentro Circonferenza: ");
    	System.out.println("X: " + p3.getBaricentro().getX() + " Y: " + p3.getBaricentro().getY());
    	System.out.println("Raggio Circonferenza: ");
    	Circonferenza c = (Circonferenza)p3;
    	System.out.println(c.getRaggio());
    	
    	//Colori
    	Colore r1 = new Rgb(10,14,15);
    	Colore cm1 = new Cmyk(34,14,15,25);
    	System.out.println("Hex Rgb: ");
    	System.out.println(r1.getHex());
    	System.out.println("Hex Cmyk: ");
    	System.out.println(cm1.getHex());
    	
    	Colore som1 = r1.somma(cm1);
    	System.out.println("Hex Rgb somma: ");
    	System.out.println(som1.getHex());
    	
    	Colore sot1 = r1.sottrazione(cm1);
    	System.out.println("Hex Rgb sottrazione: ");
    	System.out.println(sot1.getHex());
    	
    	Colore med1 = r1.media(cm1);
    	System.out.println("Hex Rgb media: ");
    	System.out.println(med1.getHex());
    	
    	Colore r2 = new Rgb(125,44,15);
    	Colore cm2 = new Cmyk(34,86,95,45);
    	
    	Colore som2 = cm2.somma(r2);
    	System.out.println("Hex Cmyk somma: ");
    	System.out.println(som2.getHex());
    	
    	Colore sot2 = cm2.sottrazione(r2);
    	System.out.println("Hex Cmyk sottrazione: ");
    	System.out.println(sot2.getHex());
    	
    	Colore med2 = cm2.media(r2);
    	System.out.println("Hex Cmyk media: ");
    	System.out.println(med2.getHex());
    	
    	
    	
    	
    	
    }
}
