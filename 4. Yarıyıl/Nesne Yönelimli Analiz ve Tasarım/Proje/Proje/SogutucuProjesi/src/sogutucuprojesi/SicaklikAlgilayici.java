/**
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr B181210057
* @since 07.05.2020
*/

package sogutucuprojesi;

import java.util.Random;

public class SicaklikAlgilayici implements ISicaklikGonder
{
    private static SicaklikAlgilayici sicaklikAlgilayici;
    private int sicaklik;

    private SicaklikAlgilayici()
    {
        sicaklikOku();
    }
        
    public static synchronized SicaklikAlgilayici getSicaklikAlgilayici()
    {
        if(sicaklikAlgilayici == null)
        {
            sicaklikAlgilayici = new SicaklikAlgilayici();
        }
        return sicaklikAlgilayici;
    }
    
    public int getSicaklik() 
    {
        return sicaklik;
    }

    public void setSicaklik(int sicaklik) 
    {
        this.sicaklik = sicaklik;
    }
    
    public int sicaklikOku()
    {
        Random rastgele = new Random();
        sicaklik = rastgele.nextInt(40);
        return sicaklik;
    }
    
    @Override
    public int sicaklikGonder(boolean kontrol4)
    { 
        if(kontrol4 == false)
        {
            return 0;
        }
        else
        {
            return this.sicaklik;
        }
    }
}