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
		T__0=1, T__1=2, T__2=3, FLOAT=4, MUL_OP=5, DIV_OP=6, REM_OP=7, ADD_OP=8, 
		SUB_OP=9, EQUALITY_OP=10, RELATIONAL_OP=11, INT=12, IDENTIFIER=13, COMMENT=14, 
		NS=15;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "FLOAT", "MUL_OP", "DIV_OP", "REM_OP", "ADD_OP", 
			"SUB_OP", "EQUALITY_OP", "RELATIONAL_OP", "INT", "IDENTIFIER", "COMMENT", 
			"NS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'('", "')'", null, "'*'", "'/'", "'%'", "'+'", "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, "FLOAT", "MUL_OP", "DIV_OP", "REM_OP", "ADD_OP", 
			"SUB_OP", "EQUALITY_OP", "RELATIONAL_OP", "INT", "IDENTIFIER", "COMMENT", 
			"NS"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\21a\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\3\2\3\2\3\3\3\3\3\4"+
		"\3\4\3\5\3\5\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13"+
		"\3\13\3\13\5\13:\n\13\3\f\3\f\3\f\3\f\3\f\3\f\5\fB\n\f\3\r\6\rE\n\r\r"+
		"\r\16\rF\3\16\3\16\7\16K\n\16\f\16\16\16N\13\16\3\17\3\17\3\17\3\17\7"+
		"\17T\n\17\f\17\16\17W\13\17\3\17\3\17\3\20\6\20\\\n\20\r\20\16\20]\3\20"+
		"\3\20\2\2\21\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16"+
		"\33\17\35\20\37\21\3\2\7\3\2\62;\4\2C\\c|\6\2\62;C\\aac|\4\2\f\f\17\17"+
		"\4\2\13\f\"\"\2h\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13"+
		"\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2"+
		"\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\3"+
		"!\3\2\2\2\5#\3\2\2\2\7%\3\2\2\2\t\'\3\2\2\2\13+\3\2\2\2\r-\3\2\2\2\17"+
		"/\3\2\2\2\21\61\3\2\2\2\23\63\3\2\2\2\259\3\2\2\2\27A\3\2\2\2\31D\3\2"+
		"\2\2\33H\3\2\2\2\35O\3\2\2\2\37[\3\2\2\2!\"\7=\2\2\"\4\3\2\2\2#$\7*\2"+
		"\2$\6\3\2\2\2%&\7+\2\2&\b\3\2\2\2\'(\5\31\r\2()\7\60\2\2)*\5\31\r\2*\n"+
		"\3\2\2\2+,\7,\2\2,\f\3\2\2\2-.\7\61\2\2.\16\3\2\2\2/\60\7\'\2\2\60\20"+
		"\3\2\2\2\61\62\7-\2\2\62\22\3\2\2\2\63\64\7/\2\2\64\24\3\2\2\2\65\66\7"+
		"?\2\2\66:\7?\2\2\678\7#\2\28:\7?\2\29\65\3\2\2\29\67\3\2\2\2:\26\3\2\2"+
		"\2;B\7@\2\2<=\7@\2\2=B\7?\2\2>B\7>\2\2?@\7>\2\2@B\7?\2\2A;\3\2\2\2A<\3"+
		"\2\2\2A>\3\2\2\2A?\3\2\2\2B\30\3\2\2\2CE\t\2\2\2DC\3\2\2\2EF\3\2\2\2F"+
		"D\3\2\2\2FG\3\2\2\2G\32\3\2\2\2HL\t\3\2\2IK\t\4\2\2JI\3\2\2\2KN\3\2\2"+
		"\2LJ\3\2\2\2LM\3\2\2\2M\34\3\2\2\2NL\3\2\2\2OP\7\61\2\2PQ\7\61\2\2QU\3"+
		"\2\2\2RT\n\5\2\2SR\3\2\2\2TW\3\2\2\2US\3\2\2\2UV\3\2\2\2VX\3\2\2\2WU\3"+
		"\2\2\2XY\b\17\2\2Y\36\3\2\2\2Z\\\t\6\2\2[Z\3\2\2\2\\]\3\2\2\2][\3\2\2"+
		"\2]^\3\2\2\2^_\3\2\2\2_`\b\20\2\2` \3\2\2\2\t\29AFLU]\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}