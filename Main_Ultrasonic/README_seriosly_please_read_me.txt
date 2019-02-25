Die Adressierung der Sensoren ist wie folgt:
 *   _________      __________   
 *  /224   232\    /0xE0  0xE8\ 
 * |           |  |            |
 * |226     230|  |0xE2    0xE6|
 *  \         /    \          /
 *    --228--        --0xE4--
 
Da das letze Bit (LSB) der Adressen irgendwie verloren geht muss bei Wire.beginTransmission immer DIE H�LFTE der Adresse gesendet werden.

Die Reichweite kann wie im BSP gezeigt auf 3m eingestellt werden, so stehen die Werte schneller zur Verf�gung (bereits nach 21ms).
Die Ausleseh�ufigkeit kann so aber nicht erh�ht werden, hierzu m�sste die Messverst�rkung zus�tzlich angepasst werden.

Eine Messung darf mit den im Bsp. gegebenen Einstellungen nur alle 65ms vorgenommen werden, da sich sonst Signale �berlagern

Solange eine Messung im Gange ist wird der Sensor nicht antworten, somit kann �ber ein Abfragen z.B. der Software-Version (Lesen im Register 0) gepr�ft werden ob die Messung fertig ist.

Das Ergebnis wird auf zwei Register aufgeteilt, da die Zahlen h�her als 255 werden k�nnen.Es stehen mehrere Echos zur Verf�gung, wenn das Signal mehrfach irgendwo abgeprallt ist.
0x02, 0x03 - Echo 1
0x04, 0x05 - Echo 2
0x06, 0x07 - Echo 3
...
0x22, 0x23 - Echo 17
(Angaben in HEX)