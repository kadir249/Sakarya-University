/**
* @author Kadir Çelik kadir.celik6@ogr.sakarya.edu.tr B181210057
* @since 07.05.2020
*/

package sogutucuprojesi;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

public class SogutucuVeritabaniServisi 
{
    public boolean kullaniciDogrula(String kullaniciAdi, String kullaniciSifresi)
    {
        ArrayList<Kullanici> kullanicilar = new ArrayList<Kullanici>();
        int kontrol = 0;
        try
        {
            Connection conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/SogutucuVeritabani",
            "postgres", "20006757");
            if (conn != null)
            {     
                System.out.println("Kullanici dogrulaniyor. Lutfen bekleyiniz.");
            }
            else
            {
                System.out.println("Bağlantı girişimi başarısız!");
            }

            String sql= "SELECT *  FROM \"Kullanici\"";

            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(sql);

            conn.close();
            String adi = null;
            String sifresi = null;

            while(rs.next())
            {
                adi = rs.getString("Adi");
                sifresi = rs.getString("Sifresi");
                kullanicilar.add(new Kullanici(adi, sifresi));
            }
            for(int i = 0; i < kullanicilar.size(); i++)           
            {
                if(kullaniciAdi.equals(kullanicilar.get(i).getAdi()) && kullaniciSifresi.equals(kullanicilar.get(i).getSifresi()))
                {
                    kontrol = 1;
                }
            }

            rs.close();
            stmt.close();
        } 
        catch (Exception e) 
        {
            e.printStackTrace();
        }
        if(kontrol != 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}