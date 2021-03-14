/**
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr B181210057
* @since 07.05.2020
*/

package sogutucuprojesi;

public class MerkeziIslemBirimi implements ISicaklikGonder
{
    private static MerkeziIslemBirimi merkeziIslemBirimi;
    private MerkeziIslemBirimi()
    {
        
    }
        
    public static synchronized MerkeziIslemBirimi getMerkeziIslemBirimi()
    {
        if(merkeziIslemBirimi == null)
        {
            merkeziIslemBirimi = new MerkeziIslemBirimi();
        }
        return merkeziIslemBirimi;
    }
   
    @Override
    public int sicaklikGonder(boolean kontrol4)
    {
        return SicaklikAlgilayici.getSicaklikAlgilayici().sicaklikGonder(kontrol4);
    }
    

    public void sogutucuAc(int derece, boolean kontrol4, boolean kontrol5)
    {
        if(derece < SicaklikAlgilayici.getSicaklikAlgilayici().sicaklikGonder(kontrol4))
        {
            if(kontrol5 == true)
            {
                System.out.println("Isteginiz eyleyiciye iletiliyor.");
            }
            else
            {
                System.out.println("Sorun ag arayuzune bildiriliyor.");
            }    
        }
        else
        {
            System.out.println("Istek eyleyiciye iletilemedi.");
        }
    }
    
    public void sogutucuKapat(boolean kontrol5)
    { 
        if(kontrol5 == true)
        {
            System.out.println("Isteginiz eyleyiciye iletiliyor.");
        }
        else
        {
            System.out.println("Sorun ag arayuzune bildiriliyor.");
        }    
    }
}