Der Ballsensor setzt sich aus einer LED und einem LDR (Fotowiderstand) zusammen.
Der LDR ist an GND gehangen und muss deshalb �ber einen PullUp-Widerstand ausgelesen werden (Prinzip Spannungsteiler).
F�r den Messvorgang muss die LED eingeschaltet werden (Pin auf HIGH), nach dem Einschalten muss dem Lichtsensor Zeit gegeben werden, auf das Licht zu reagieren (min 5ms).
Alternativ kann das Licht durchgehend an sein, was jedoch zu Problemen mit anderen Teams f�hren kann.