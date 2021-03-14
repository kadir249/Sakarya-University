/**
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr B181210057
* @since 07.05.2020
*/

package sogutucuprojesi;

public interface ISubject 
{
    public void ekle(IObserver o);
    public void sil(IObserver o);
    public void mesaj1(int kontrol6);
    public void mesaj2();
    public void mesaj3(boolean kontrol4);
}