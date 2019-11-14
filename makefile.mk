proyectil.png : datos.dat grafico.py
    python grafico.py
    
datos.dat : proyectil.x
           c++ proyectil,coo -o proyectil.x
           
clean : rm datos.dat proyectil.x proyectil.png