ANTLR4=java -Xmx500M -cp "/usr/local/lib/antlr-4.8-complete.jar:$CLASSPATH" org.antlr.v4.Tool
GRAMMAR=calc

grammar: $(GRAMMAR).g4
		 $(ANTLR4) -Dlanguage=Cpp -no-listener -visitor $(GRAMMAR).g4

visitor:
		g++ main.cpp -o $(GRAMMAR) -I/usr/local/include/antlr4-runtime -lantlr4-runtime
	 

clean:	
	    rm -f $(GRAMMAR)BaseVisitor* $(GRAMMAR)*.interp $(GRAMMAR)Lexer* $(GRAMMAR)Parser* $(GRAMMAR)Visitor* $(GRAMMAR)*.tokens $(GRAMMAR)

