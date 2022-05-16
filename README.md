# MQTT Protokolü Tabanlı Akıllı Balık Çiftliği
Bu proje MQTT Prokolü tabanlı mobil bir akıllı balık çiftliği uygulamasını içermektedir.
                                                    Raspberry Pi Kurulum İşlemleri
Raspberry Pi 0’ya işletim sistemi kurulabilmesi için  imager uygulaması kurulumu gerekmektedir. Bu uygulama https://www.raspberrypi.com/software/ adresinden indirilebilir. Uygulama çalıştırıldıktan sonra CHOOSE OS seçeneğinden Raspberry Pi Operating System seçilmelidir. 
                                                          SSH ve Wifi Kurulumu
Raspberry Pi 0’ya local ağ üzerinden bağlantı kurabilmek için Kurulumlar.pdf dökümanında gösterilen işlemler yapılmalıdır. Eğer tercih edilmezse monitör, klavye ve fare bağlayarak da kullanılabilir. 
                                                              MQTT Kurulumu
ESP8266 üzerinden publish edilen mesajların içeriğini görmek için Raspberry Pi terminali üzerinden Kurulumlar.pdf dökümanında gösterildiği şekilde komutlar kullanılarak yükleme işlemleri yapılabilir. Bu sayede terminal üzerinden gelen mesajlar okunabilir ama bu projede yazılan bir python script üzerinden mesajları alma işlemleri ve kullanıcıya mail gönderme işlemi tercih edilmiştir. 
                                                      SSMTP Mail Uygulaması Kurulumu
Raspberry Pi üzerinden kullanıcılara mail göndermek için dökümanda belirtildiği şekilde ssmtp mail uygulaması kurulmalıdır ve maili gönderecek gmail hesabında Gmail 2 adımlı doğrulama aktifleştirme açılmalıdır.
