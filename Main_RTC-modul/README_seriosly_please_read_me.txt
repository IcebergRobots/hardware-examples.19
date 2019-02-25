Als RTC kommt hier der sehr genaue DS3231-IC zum Einsatz.
Mit der Funktion Clock.oscillatorCheck() lässt sich wie im Beispiel gezeigt überprüfen ob die Uhr funktioniert.

Zusätzlich zu den im Bsp. gezeigten Funktionen verfügt der Chip über ein Termometer welches sich in der Bibliothek mit Clock.getTemperature() auslesen lässt, sowie zwei Alarmspeicher. Zum verwenden der Alarme siehe Bsp. der Bibliothek.