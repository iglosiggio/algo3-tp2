salida%.txt:
	../../arbol-compr.algo 300 $* < entrada.txt > $@

foto%.png: salida%.txt
	../../scripts/salida2foto.sh $^ > $@

video.mp4: $(shell env LC_NUMERIC=C seq -ffoto%04.1f.png 0 0.1 10)
	ffmpeg -framerate 20 -pattern_type glob -i foto\*.png \
	       -vf "scale=trunc(iw/2)*2:trunc(ih/2)*2" -pix_fmt yuv420p $@

.PRECIOUS: %.png salida%.txt
