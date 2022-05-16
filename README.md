# MQTT Protokolü Tabanlı Akıllı Balık Çiftliği
Bu proje MQTT Prokolü tabanlı mobil bir akıllı balık çiftliği uygulamasını içermektedir.

Raspberry Pi Kurulum İşlemleri:
Raspberry Pi 0’ya işletim sistemi kurulabilmesi için  imager uygulaması kurulumu gerekmektedir. Bu uygulama https://www.raspberrypi.com/software/ adresinden indirilebilir. Uygulama çalıştırıldıktan sonra CHOOSE OS seçeneğinden Raspberry Pi Operating System seçilmelidir. 

SSH ve Wifi Kurulumu:
Raspberry Pi 0’ya local ağ üzerinden bağlantı kurabilmek için Kurulumlar.pdf dökümanında gösterilen işlemler yapılmalıdır. Eğer tercih edilmezse monitör, klavye ve fare bağlayarak da kullanılabilir. 

MQTT Kurulumu:
ESP8266 üzerinden publish edilen mesajların içeriğini görmek için Raspberry Pi terminali üzerinden Kurulumlar.pdf dökümanında gösterildiği şekilde komutlar kullanılarak yükleme işlemleri yapılabilir. Bu sayede terminal üzerinden gelen mesajlar okunabilir ama bu projede yazılan bir python script üzerinden mesajları alma işlemleri ve kullanıcıya mail gönderme işlemi tercih edilmiştir. 

SSMTP Mail Uygulaması Kurulumu:
Raspberry Pi üzerinden kullanıcılara mail göndermek için dökümanda belirtildiği şekilde ssmtp mail uygulaması kurulmalıdır ve maili gönderecek gmail hesabında Gmail 2 adımlı doğrulama aktifleştirme açılmalıdır. 

Raspberry pi 0: 
Broker.py script'i çalıştırıldığında sürekli olarak havuzlara bağlı olan esp8266 modüllerinden mesaj beklemektedir.
send_mail.sh Raspberry pi üzerinde çalıştırılacaktır.
Python script'i içinde aynı zamanda subprocess ile ssmtp mail uygulamasını kullanarak mail gönderen send_mail.sh shell script'ini çalıştırmaktadır.
ESP8266 mesajları sadece oksijen değerleri düşük olduğunda gönderir ve mesajı alan broker kullanıcıya doğru mail script'ini çalıştırarak kullanıcıyı bilgilendirir.

ESP8266:
ESP 8266 üzerinde oksijen sensörü ölçümleri yerine test ortamı olduğu için potansiyometre kullanılmıştır.
Havuzların belirli bölgelerde bulunan her birisine kimlik numarası atanmıştır ama eğer istenilirse GPS uygulaması içeren kodlar kullanılarak havuzun konum bilgileri gönderilebilir.
Potansiyometrenin ölçdüğü değer 750 den fazlaysa broker'a doğru publish işlemi gerçeleştirilmektedir.
Değerin 750 den fazla olması gerçek uygulamada oksijen sensörünün sudaki oksijen miktarını düşük olarak ölçmesine karşılık gelmektedir.
