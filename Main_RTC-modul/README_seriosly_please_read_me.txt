Als RTC kommt hier der sehr genaue DS3231-IC zum Einsatz.
Mit der Funktion Clock.oscillatorCheck() l�sst sich wie im Beispiel gezeigt �berpr�fen ob die Uhr funktioniert.

Zus�tzlich zu den im Bsp. gezeigten Funktionen verf�gt der Chip �ber ein Termometer welches sich in der Bibliothek mit Clock.getTemperature() auslesen l�sst, sowie zwei Alarmspeicher. Zum verwenden der Alarme siehe Bsp. der Bibliothek.