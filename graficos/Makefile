clean:
	rm -f *.pdf

%.pdf: %.dot
	dot -Tpdf $^ > $@

%.pdf: plots/%.plot
	cd plots; gnuplot $*.plot

ver_%: %.pdf
	xdg-open $^

.PHONY: ver_% clean
