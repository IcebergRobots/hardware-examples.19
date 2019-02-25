Die Adressierung der Sensoren ist wie folgt:
 *   _________      __________   
 *  /224   232\    /0xE0  0xE8\ 
 * |           |  |            |
 * |226     230|  |0xE2    0xE6|
 *  \         /    \          /
 *    --228--        --0xE4--
 
Da das letze Bit (LSB) der Adressen irgendwie verloren geht muss bei Wire.beginTransmission immer DIE HÄLFTE der Adresse gesendet werden.

Die Reichweite kann wie im BSP gezeigt auf 3m eingestellt werden, so stehen die Werte schneller zur Verfügung (bereits nach 21ms).
Die Auslesehäufigkeit kann so aber nicht erhöht werden, hierzu müsste die Messverstärkung zusätzlich angepasst werden.

Eine Messung darf mit den im Bsp. gegebenen Einstellungen nur alle 65ms vorgenommen werden, da sich sonst Signale überlagern

Solange eine Messung im Gange ist wird der Sensor nicht antworten, somit kann über ein Abfragen z.B. der Software-Version (Lesen im Register 0) geprüft werden ob die Messung fertig ist.

Das Ergebnis wird auf zwei Register aufgeteilt, da die Zahlen höher als 255 werden können.Es stehen mehrere Echos zur Verfügung, wenn das Signal mehrfach irgendwo abgeprallt ist.
0x02, 0x03 - Echo 1
0x04, 0x05 - Echo 2
0x06, 0x07 - Echo 3
...
0x22, 0x23 - Echo 17
(Angaben in HEX)