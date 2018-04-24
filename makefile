g1.png: datos.txt grafica1.py
	python grafica1.py
datos.txt: eje22
	./eje22 > datos.txt
eje22: eje22.cpp
	c++ eje22.cpp -o eje22
