BSM 309 İşletim Sistemleri Dersi Projesi B Şubesi (Prof. Dr. Ahmet ÖZMEN) 1. Grup
Dosya Adı: Proje
Proje Adı: B Şubesi 1. Grup Kabuk Projesi
Proje Grup Elemanları:	Mücahid Işık b181210111 2. Öğretim
			Duhan Uzun b181210051 2. Öğretim
			Kadir Çelik b181210057 2. Öğretim
			Hüseyin Hıra b181210105 2. Öğretim
			İbrahim Cansun b181210108 1. Öğretim
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
													Tasarıma Genel Bakış
	Programımız batch modunda ve interaktif modda çalışabilmektedir. Eğer proje "./proje" komutu ile çalıştırılırsa interaktif, "./proje kmt.txt" gibi bir komutla çalıştırılırsa batch modunda çalışmaktadır. Projenin hangi modda
çalıştırılacağını anlamak için main bloğunda "argc" sayısını kontrol edilir. Eğer argc 1'e eşitse interaktif, 2'ye eşitse batch modunda çalıştırılır. Eğer argc bu iki eşitliği de sağlamıyorsa ekrana bir uyarı mesajı yazılır.
 	
 	Eğer kullanıcı programı interaktif modda çalıştırırsa prompt bastırılır. Prompt basıldıktan sonra eğer kullanıcı 512 karakterden uzun komut girmediyse kullanıcının girdiği komutlar çalıştırılır. Eğer kullanıcı 512 karakterden
uzun komut girdiyse ekrana hata mesajı yazdırılır. Kullanıcının girdiği komutlar ilk olarak strtok() fonksiyonunun ";"e göre parçalanır. Parçalanan bu komutlar calistir() fonksiyonuna yollanır. calistir() fonksiyonunda ";"e göre
parçalanmış olan komutlar parcala() fonksiyonu ile boşluk karakterine göre parçalanır. Eğer komutlar arasında birden fazla boşluk karakteri varsa boslukSilme() fonksiyonu çağrılır. boslukSilme() fonksiyonu ile gereksiz olan boşluklar
(white space) silinir. Daha sonra bu komutlar iki boyutlu bir karakter dizisine atılır. Komutlar diziye atıldıktan sonra komut() fonksiyonu ile çalıştırılır. komut() fonksiyonunda komutların paralel olarak çalıştırılması sağlanır.
Komutlar pidlerine göre sırasıyla çalışır. Ebeveyn process, yavru process sonlanana kadar bekler. Böylece paralel çalışma sağlanmış olur.
 	
 	Projemizde sistem komutlarına ek olarak cd, clear, quit ve help komutlarını da tasarladık. cd komutu komutCd() fonksiyonu, clear komutu komutClear() fonksiyonu, quit komutu komutQuit() fonkisiyonu, help komutu ise komutHelp()
fonksiyonu ile çalıştırılmaktadır. Kullanıcı; cd komutu ile istediği dosya dizinine gider, clear komutu ile interaktif mod ekranını temizler, quit komutu ile uygulamadan çıkış yapar, help komutuyla ise kabuğumuz hakkında bilgi
edinebilir. 
 	
 	Batch modunda ise kullanıcı bir dosyaya girdiği komutları okur ve icra eder. Bu modda da 512 karakter sınırlaması vardır. Dosyadan bir satır okunur ve bu satırdaki komutlar interaktif moddakine benzer bir şekilde icar edilir.
 Her iki moddan da sadece "quit" komutu ve "CTRL+D" ile çıkış yapılabilmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
													    Özel Durumlar
1- Komut Satırına Veri Girilmeyip Enter'a Basılması: Bu durumda kabuk hata vermez, yeni bir prompt basar ve çalışmaya devam eder. 

2- Noktalı Virgüller Arasına Veri Girilmemesi: Komut satırına sadece "; ;" benzeri bir komut yazılırsa kabuk hata vermez, yeni bir prompt basar ve çalışmaya devam eder. Komut satırına "ls ; ; mkdir a" benzeri bir komut yazılırsa "ls"
ve "mkdir a" komutlarını çalıştırır. "; ;" yeri es geçer.

3- Yanlış Komut Girilmesi: Bu durumda kullanıcıya stderr() ile bir hata mesajı yazdırılır ve kabuk çalışmaya devam eder.

4- Komut Satırına veya Batch Dosyasına 512 Karakterden Fazla Veri Girilmesi: İnteraktif modda ise kullanıcıya hata mesajı yazdırılır ve kabuk yeni bir prompt basarak çalışmaya devam eder. Batch modunda ise kullanıcıya sadece hata mesajı
yazdırılır.

5- Batch Dosyası Yoksa: Ekrana dosyanın bulunamadığına dair hata mesajı yazdırılır.

6- Komut Satırında Fazladan Karakter Boşluklarının Bulunması: Bu durumda kod çalışmaya devam eder.

7- CTRL+Z, CTRL+C veya CTRL+ALT GR+\ Girilmesi: Kabuk yeni bir prompt basar ve çalışmaya devam eder.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
												      Bilinen Hatalar ve Sorunlar
1- Noktalı virgül bir komuta bitişik olarak yazılırsa kabuk o komuttan sonraki komutları icra edemiyor.
Örnek: prompt> ls; ls -l şeklinde bir komut yazılmış olsun. Bu durumda sadece ls komutu icra edilir ve ekrana yeni bir prompt bastırılır.

2- Batch dosyasında "ls -l", "ls -n" benzeri komut yazılması durumunda kabuk bu komutları icra edemiyor, ekrana hata mesajı basıyor ve diğer komutları icra etmeye devam ediyor. 
