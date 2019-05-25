%.pdf: %.dot
	dot -Tpdf $^ > $@

ver_%: %.pdf
	xdg-open $^

.PHONY: ver_%
