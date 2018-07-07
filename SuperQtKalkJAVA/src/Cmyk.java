
import static java.lang.Math.round;
import static java.lang.Math.abs;
import static java.lang.Math.max;

public class Cmyk implements Colore {
    private int cyan;
    private int magenta;
    private int yellow;
    private int black;
    private static int CMYK_MAX_VALUE = 100;

    public Cmyk(int c, int m, int y, int k) {
    	if(c > CMYK_MAX_VALUE)
    		cyan = CMYK_MAX_VALUE;
    	else if (c < 0)
    		cyan = 0;
    	else
    		cyan = c;
    	
    	if(m > CMYK_MAX_VALUE)
    		magenta = CMYK_MAX_VALUE;
    	else if (m < 0)
    		magenta = 0;
    	else
    		magenta = m;
    	
    	if(y > CMYK_MAX_VALUE)
    		yellow = CMYK_MAX_VALUE;
    	else if (y < 0)
    		yellow = 0;
    	else
    		yellow = y;
    	
    	if(k > CMYK_MAX_VALUE)
    		black = CMYK_MAX_VALUE;
    	else if (k < 0)
    		black = 0;
    	else
    		black = k;
    }

    public Cmyk(String s) {
        String r = s.substring(1,2);
        String g = s.substring(3,4);
        String b = s.substring(5,6);
        double r1 =Integer.parseInt(r,16);
        double g1 = Integer.parseInt(g,16);
        double b1 = Integer.parseInt(b,16);
        r1 = r1/255;
        g1 = g1/255;
        b1 = b1/255;
        double max = max(r1,g1);
        double max2=0;
        max2 = max(max,b1);
        double bla = 1 - max2;
        double cy = (1-r1-bla) / (1-bla);
        double mag = (1-g1-bla) / (1-bla);
        double yel = (1-b1-bla) / (1-bla);
        cyan = (int)round(cy*100);
        magenta = (int)round(mag*100);
        yellow = (int)round(yel*100);
        black = (int)round(bla*100);
    }

    public int getCyan() {
        return cyan;
    }
    public int getMagenta() {
        return magenta;
    }
    public int getYellow() {
        return yellow;
    }
    public int getBlack() {
        return black;
    }

    void setCyan(int c) {
    	if(c > CMYK_MAX_VALUE)
    		cyan = CMYK_MAX_VALUE;
    	else if (c < 0)
    		cyan = 0;
    	else
    		cyan = c;
    }

    void setMagenta(int m) {
    	if(m > CMYK_MAX_VALUE)
    		magenta = CMYK_MAX_VALUE;
    	else if (m < 0)
    		magenta = 0;
    	else
    		magenta = m;
    }

    void setYellow(int y) {
    	if(y > CMYK_MAX_VALUE)
    		yellow = CMYK_MAX_VALUE;
    	else if (y < 0)
    		yellow = 0;
    	else
    		yellow = y;
    }

    void setBlack(int k) {
    	if(k > CMYK_MAX_VALUE)
    		black = CMYK_MAX_VALUE;
    	else if (k < 0)
    		black = 0;
    	else
    		black = k;
    }

    
    public String getHex() {
        String temp = "#";
        double c = cyan;
        double m = magenta;
        double y = yellow;
        double bl = black;

        double r1 = round(255*( 1 - c / 100) * ( 1 - bl / 100));
        double g1 = round(255*( 1 - m / 100) * ( 1 - bl / 100));
        double b1 = round(255*( 1 - y / 100) * ( 1 - bl / 100));

        String r = String.format("%02X", (int)r1);
        String g = String.format("%02X", (int)g1);
        String b = String.format("%02X", (int)b1);
        return temp + r + g + b;
    }

    
    public Cmyk somma(Colore c) {
        int c1 = cyan;
        int m = magenta;
        int y = yellow;
        int k = black;
        if(c instanceof Cmyk) {
            Cmyk temp = (Cmyk) c;
            c1 += temp.getCyan();
            m += temp.getMagenta();
            y += temp.getYellow();
            k += temp.getBlack();
        }
        else {
            Cmyk t = new Cmyk(c.getHex());
            c1 += t.getCyan();
            m += t.getMagenta();
            y += t.getYellow();
            k += t.getBlack();

        }
        return new Cmyk(c1,m,y,k);

    }

    
    public Cmyk sottrazione(Colore c) {
        int c1 = cyan;
        int m = magenta;
        int y = yellow;
        int k = black;
        if(c instanceof Cmyk) {
            Cmyk temp = (Cmyk) c;
            c1 -= temp.getCyan();
            m -= temp.getMagenta();
            y -= temp.getYellow();
            k -= temp.getBlack();
        }
        else {
            Cmyk t = new Cmyk(c.getHex());
            c1 -= t.getCyan();
            m -= t.getMagenta();
            y -= t.getYellow();
            k -= t.getBlack();

        }
        if(c1<0) c1 = 0;
        if(m<0) m = 0;
        if(y<0) y = 0;
        if(k<0) k = 0;
        return new Cmyk(c1,m,y,k);

    }

    
    public Cmyk media(Colore c) {
        int c1 = cyan;
        int m = magenta;
        int y = yellow;
        int k = black;
        if(c instanceof Cmyk) {
            Cmyk temp = (Cmyk) c;
            c1 += temp.getCyan();
            m += temp.getMagenta();
            y += temp.getYellow();
            k += temp.getBlack();
        }
        else {
            Cmyk t = new Cmyk(c.getHex());
            c1 += t.getCyan();
            m += t.getMagenta();
            y += t.getYellow();
            k += t.getBlack();

        }
        return new Cmyk(abs(c1/2),abs(m/2),abs(y/2),abs(k/2));

    }
    
    public int getMaxValues() {
        return CMYK_MAX_VALUE;
    }
}
