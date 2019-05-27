clean:
	rm -f *.pdf

%.pdf: %.dot
	dot -Tpdf $^ > $@

ver_%: %.pdf
	xdg-open $^

.PHONY: ver_% clean
