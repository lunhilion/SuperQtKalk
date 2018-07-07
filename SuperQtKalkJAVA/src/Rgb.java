import static java.lang.Math.abs;

public class Rgb implements Colore {
    private int red;
    private int green;
    private int blue;
    private static int RGB_MAX_VALUE = 255;

    public Rgb(int r, int g, int b) {
    	if(r > RGB_MAX_VALUE)
    		red = RGB_MAX_VALUE;
    	else if (r < 0)
    		red = 0;
    	else
    		red = r;
    	
    	if(g > RGB_MAX_VALUE)
    		green = RGB_MAX_VALUE;
    	else if (g < 0)
    		green = 0;
    	else
    		green = g;
    	
    	if(b > RGB_MAX_VALUE)
    		blue = RGB_MAX_VALUE;
    	else if (b < 0)
    		blue = 0;
    	else
    		blue = b;
    }

    public Rgb(String s) {
        String r = s.substring(1,2);
        String g = s.substring(3,4);
        String b = s.substring(5,6);
        red = Integer.parseInt(r,16);
        green = Integer.parseInt(g,16);
        blue = Integer.parseInt(b,16);
    }

    int getRed() {
        return red;
    }
    int getGreen() {
        return green;
    }
    int getBlue() {
        return blue;
    }
    
    void setRed(int r) {
    	if(r > RGB_MAX_VALUE)
    		red = RGB_MAX_VALUE;
    	else if (r < 0)
    		red = 0;
    	else
    		red = r;
    }
    
    void setGreen(int g) {
    	if(g > RGB_MAX_VALUE)
    		green = RGB_MAX_VALUE;
    	else if (g < 0)
    		green = 0;
    	else
    		green = g;
    }
    
    void setBlue(int b) {
    	if(b > RGB_MAX_VALUE)
    		blue = RGB_MAX_VALUE;
    	else if (b < 0)
    		blue = 0;
    	else
    		blue = b;
    }

    
    public String getHex() {
        String temp = "#";
        String r = String.format("%02X", red);
        String g = String.format("%02X", green);
        String b = String.format("%02X", blue);
        return temp + r + g + b;
    }

    
    public Rgb somma(Colore c) {
        int r = red;
        int g = green;
        int b = blue;
        if(c instanceof Rgb) {
            Rgb t = (Rgb) c;
            r += t.getRed();
            g += t.getGreen();
            b += t.getBlue();
        }
        else {
            Rgb p = new Rgb(c.getHex());
            r += p.getRed();
            g += p.getGreen();
            b += p.getBlue();
        }
        return new Rgb(r,g,b);
    }
    
    public Rgb sottrazione(Colore c) {
        int r = red;
        int g = green;
        int b = blue;
        if(c instanceof Rgb) {
            Rgb t = (Rgb) c;
            r -= t.getRed();
            g -= t.getGreen();
            b -= t.getBlue();
        }
        else {
            Rgb p = new Rgb(c.getHex());
            r -= p.getRed();
            g -= p.getGreen();
            b -= p.getBlue();
        }

        if(r<0) r = 0;
        if(g<0) g = 0;
        if(b<0) b = 0;
        return new Rgb(r,g,b);
    }
    
    public Colore media(Colore c) {
        int r = red;
        int g = green;
        int b = blue;
        if(c instanceof Rgb) {
            Rgb t = (Rgb) c;
            r += t.getRed();
            g += t.getGreen();
            b += t.getBlue();
        }
        else {
            Rgb p = new Rgb(c.getHex());
            r += p.getRed();
            g += p.getGreen();
            b += p.getBlue();
        }
        return new Rgb(abs(r/2),abs(g/2),abs(b/2));
    }

public int getMaxValues() {
    return RGB_MAX_VALUE;
}

}