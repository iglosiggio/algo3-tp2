salida%.txt:
	../../arbol-compr.algo $* 0.8 < entrada.txt > $@

foto%.png: salida%.txt
	../../scripts/salida2foto.sh $^ > $@

variar-k.mp4: $(shell seq -ffoto%04.0f.png 0 800)
	ffmpeg -framerate 30 -i foto%04d.png \
	       -vf "scale=trunc(iw/2)*2:trunc(ih/2)*2" -pix_fmt yuv420p $@

.PRECIOUS: %.png salida%.txt
