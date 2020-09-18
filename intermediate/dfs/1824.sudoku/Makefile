CFLAGS := -Wall
# CFLAGS := -Duse_pr

IN := in0
OUT := out0

define build
$(eval 
$(2): FORCE $(1)
	g++ $(CFLAGS) -o $$@ $(2).cpp
	./$(2) $(3) 2>&1 | tee $(2).txt
	diff -q -Z $(2).txt $(OUT) && echo "Ok" || echo "Fail"
	@echo

OUTS += $(2) $(2).txt
)
endef

$(call build,main,bfrc,< $(IN))
$(call build,,main,< $(IN))

clean:
	rm -rf $(OUTS)

.PHONY: FORCE

reset:
	find ! -name Makefile | xargs rm -rf

