// Generated from Expr.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ExprLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, FLOAT=9, 
		ARITH_OP=10, EQ_OP=11, REL_OP=12, INT=13, ID=14, COMMENT=15, NS=16;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "FLOAT", 
			"ARITH_OP", "EQ_OP", "REL_OP", "INT", "ID", "COMMENT", "NS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'-'", "'('", "')'", "'*'", "'/'", "'%'", "'+'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, "FLOAT", "ARITH_OP", 
			"EQ_OP", "REL_OP", "INT", "ID", "COMMENT", "NS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public ExprLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Expr.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\22e\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\3\2\3\2\3"+
		"\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\n\3\n"+
		"\3\13\3\13\3\f\3\f\3\f\3\f\5\f>\n\f\3\r\3\r\3\r\3\r\3\r\3\r\5\rF\n\r\3"+
		"\16\6\16I\n\16\r\16\16\16J\3\17\3\17\7\17O\n\17\f\17\16\17R\13\17\3\20"+
		"\3\20\3\20\3\20\7\20X\n\20\f\20\16\20[\13\20\3\20\3\20\3\21\6\21`\n\21"+
		"\r\21\16\21a\3\21\3\21\2\2\22\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13"+
		"\25\f\27\r\31\16\33\17\35\20\37\21!\22\3\2\b\5\2,-//\61\61\3\2\62;\4\2"+
		"C\\c|\6\2\62;C\\aac|\4\2\f\f\17\17\4\2\13\f\"\"\2l\2\3\3\2\2\2\2\5\3\2"+
		"\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21"+
		"\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2"+
		"\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\3#\3\2\2\2\5%\3\2\2\2\7\'\3"+
		"\2\2\2\t)\3\2\2\2\13+\3\2\2\2\r-\3\2\2\2\17/\3\2\2\2\21\61\3\2\2\2\23"+
		"\63\3\2\2\2\25\67\3\2\2\2\27=\3\2\2\2\31E\3\2\2\2\33H\3\2\2\2\35L\3\2"+
		"\2\2\37S\3\2\2\2!_\3\2\2\2#$\7=\2\2$\4\3\2\2\2%&\7/\2\2&\6\3\2\2\2\'("+
		"\7*\2\2(\b\3\2\2\2)*\7+\2\2*\n\3\2\2\2+,\7,\2\2,\f\3\2\2\2-.\7\61\2\2"+
		".\16\3\2\2\2/\60\7\'\2\2\60\20\3\2\2\2\61\62\7-\2\2\62\22\3\2\2\2\63\64"+
		"\5\33\16\2\64\65\7\60\2\2\65\66\5\33\16\2\66\24\3\2\2\2\678\t\2\2\28\26"+
		"\3\2\2\29:\7?\2\2:>\7?\2\2;<\7#\2\2<>\7?\2\2=9\3\2\2\2=;\3\2\2\2>\30\3"+
		"\2\2\2?F\7@\2\2@A\7@\2\2AF\7?\2\2BF\7>\2\2CD\7>\2\2DF\7?\2\2E?\3\2\2\2"+
		"E@\3\2\2\2EB\3\2\2\2EC\3\2\2\2F\32\3\2\2\2GI\t\3\2\2HG\3\2\2\2IJ\3\2\2"+
		"\2JH\3\2\2\2JK\3\2\2\2K\34\3\2\2\2LP\t\4\2\2MO\t\5\2\2NM\3\2\2\2OR\3\2"+
		"\2\2PN\3\2\2\2PQ\3\2\2\2Q\36\3\2\2\2RP\3\2\2\2ST\7\61\2\2TU\7\61\2\2U"+
		"Y\3\2\2\2VX\n\6\2\2WV\3\2\2\2X[\3\2\2\2YW\3\2\2\2YZ\3\2\2\2Z\\\3\2\2\2"+
		"[Y\3\2\2\2\\]\b\20\2\2] \3\2\2\2^`\t\7\2\2_^\3\2\2\2`a\3\2\2\2a_\3\2\2"+
		"\2ab\3\2\2\2bc\3\2\2\2cd\b\21\2\2d\"\3\2\2\2\t\2=EJPYa\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}