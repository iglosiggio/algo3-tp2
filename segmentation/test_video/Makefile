salida%.txt:
	../arbol-compr.algo $* < entrada.txt > $@

foto%.png: salida%.txt
	../../scripts/salida2foto.sh $^ > $@

video.mp4: $(shell seq -ffoto%04.0f.png 0 4000)
	ffmpeg -framerate 30 -i foto%04d.png $@

.PRECIOUS: %.png %.txt
