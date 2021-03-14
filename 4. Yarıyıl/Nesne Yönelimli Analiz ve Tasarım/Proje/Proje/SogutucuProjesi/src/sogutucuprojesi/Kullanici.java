/**
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr B181210057
* @since 07.05.2020
*/

package sogutucuprojesi;

public class Kullanici implements IObserver 
{
    private String adi;
    private String sifresi;
    
    public Kullanici(String adi, String sifresi)
    {
        this.adi = adi;
        this.sifresi = sifresi;
    }
    
    public String getAdi() {
        return adi;
    }

    public void setAdi(String adi) {
        this.adi = adi;
    }

    public String getSifresi() {
        return sifresi;
    }

    public void setSifresi(String sifresi) {
        this.sifresi = sifresi;
    }
    
    @Override
    public void guncelleme(String mesaj)
    {
        System.out.println("Kullaniciya Gelen Mesaj->" + mesaj);
    }
}