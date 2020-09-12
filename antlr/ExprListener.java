// Generated from Expr.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ExprParser}.
 */
public interface ExprListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ExprParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(ExprParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(ExprParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#var_decl}.
	 * @param ctx the parse tree
	 */
	void enterVar_decl(ExprParser.Var_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#var_decl}.
	 * @param ctx the parse tree
	 */
	void exitVar_decl(ExprParser.Var_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#dec}.
	 * @param ctx the parse tree
	 */
	void enterDec(ExprParser.DecContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#dec}.
	 * @param ctx the parse tree
	 */
	void exitDec(ExprParser.DecContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#method_decl}.
	 * @param ctx the parse tree
	 */
	void enterMethod_decl(ExprParser.Method_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#method_decl}.
	 * @param ctx the parse tree
	 */
	void exitMethod_decl(ExprParser.Method_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#method_arg}.
	 * @param ctx the parse tree
	 */
	void enterMethod_arg(ExprParser.Method_argContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#method_arg}.
	 * @param ctx the parse tree
	 */
	void exitMethod_arg(ExprParser.Method_argContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(ExprParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(ExprParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#method_call}.
	 * @param ctx the parse tree
	 */
	void enterMethod_call(ExprParser.Method_callContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#method_call}.
	 * @param ctx the parse tree
	 */
	void exitMethod_call(ExprParser.Method_callContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(ExprParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(ExprParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(ExprParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(ExprParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#location}.
	 * @param ctx the parse tree
	 */
	void enterLocation(ExprParser.LocationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#location}.
	 * @param ctx the parse tree
	 */
	void exitLocation(ExprParser.LocationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(ExprParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(ExprParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(ExprParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(ExprParser.TypeContext ctx);
}