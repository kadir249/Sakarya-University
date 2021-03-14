/**
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr B181210057
* @since 07.05.2020
*/

package sogutucuprojesi;

public class Eyleyici
{
    private static Eyleyici eyleyici;
    private Eyleyici()
    {
        
    }
        
    public static synchronized Eyleyici getEyleyici()
    {
        if(eyleyici == null)
        {
            eyleyici = new Eyleyici();
        }
        return eyleyici;
    }
    
    public void sogutucuAc()
    {
        System.out.println("Isteginiz eyleyiciye iletildi.");
    }
    
    public void sogutucuKapat()
    {
        System.out.println("Isteginiz eyleyiciye iletildi.");
    }
}