

import org.apache.log4j.ConsoleAppender;
import org.apache.log4j.Level;
import org.apache.log4j.Logger;
import org.apache.log4j.PatternLayout;
import org.owasp.esapi.ESAPI;


public class GlobalLogger {
    private final Logger logger;
    private final Logger pctLogger; //1.1
    private final Logger batchOutwardLogger;

    public static GlobalLogger getLogger(Class<?> cls) {
        return getLogger (cls.getName());
    }

    public static GlobalLogger getLogger(String pkgName) {
        return new GlobalLogger(Logger.getLogger(pkgName));
    }
    
    public static GlobalLogger getPCTLogger(String loggerName) { //1.1
        return new GlobalLogger(Logger.getLogger(loggerName));
    }
    
    public static GlobalLogger getBatchOutwardLogger(String loggerName) {
        return new GlobalLogger(Logger.getLogger(loggerName));
    }

    private GlobalLogger(Logger logger) {
	 this.pctLogger=Logger.getLogger("PCTLog"); //1.1
	 this.batchOutwardLogger=Logger.getLogger("BOC3D3Log");
        this.logger = logger;

    }
    
    public void logPct(Object message){ //1.1
    	pctLogger.info(validateInput(message));
    }
    
    public void logBatchOutwardError(Object message){
    	batchOutwardLogger.info(validateInput(message));
    }

    public boolean isTrace() {
        return logger.isEnabledFor(Level.TRACE);
    }

    public void trace(Object message){
    	if (isTrace()) {
    		logger.trace(lineNumber() + ", Ipe2TransRef=" + ProcessRuntime.getRequestId() + ", " +validateInput( message));
    	}
    }
    
    public void trace(Object message, Throwable t){
    	if(isTrace()){
    		logger.trace(lineNumber() + ", Ipe2TransRef=" + ProcessRuntime.getRequestId() + ", " + validateInput(message), t);
    	}
    }

    public boolean isDebug() {
        return logger.isEnabledFor(Level.DEBUG);
    }
    
    public void debug(Object message){
    	if(isDebug()){
    		logger.debug(lineNumber() + ", Ipe2TransRef=" + ProcessRuntime.getRequestId() + ", " + validateInput(message));
    	}
    }
    
    public void debug(Object message, Throwable t){
    	if(isDebug()){
    		logger.debug(lineNumber() + ", Ipe2TransRef=" + ProcessRuntime.getRequestId() + ", " +validateInput( message), t);
    	}
    }

    public boolean isInfo() {
        return logger.isEnabledFor(Level.INFO);
    }
    
    public void info(Object message){
    	if(isInfo()){
    		logger.info(lineNumber() + ", Ipe2TransRef=" + ProcessRuntime.getRequestId() + ", " +validateInput(message));
    	}
    }
    
    public void info(Object message, Throwable t){
    	if(isInfo()){
    		logger.info(lineNumber() + ", Ipe2TransRef=" + ProcessRuntime.getRequestId() + ", " + validateInput(message), t);
    	}
    }

    public boolean isWarn() {
        return logger.isEnabledFor(Level.WARN);
    }
    
    public void warn(Object message){
    	if(isWarn()){
    		logger.warn(lineNumber() + ", Ipe2TransRef=" + ProcessRuntime.getRequestId() + ", " + validateInput(message));
    	}
    }
    
    public void warn(Object message, Throwable t){
    	if(isWarn()){
    		logger.warn(lineNumber() + ", Ipe2TransRef=" + ProcessRuntime.getRequestId() + ", " + validateInput(message), t);
    	}
    }
    
    public void error(Object message){
    	logger.error(lineNumber() + ", Ipe2TransRef=" + ProcessRuntime.getRequestId() + ", " + validateInput(message));
    }
    
    public void error(Object message, Throwable t){
    	logger.error(lineNumber() + ", Ipe2TransRef=" + ProcessRuntime.getRequestId() + ", " + validateInput(message), t);
    }

    /*
     * Get the Actual Line Number
     */
    private String lineNumber() {
        StackTraceElement threadTrackArray[] = Thread.currentThread().getStackTrace();
        if (threadTrackArray.length > 3) {
            return ":" + Integer.toString(threadTrackArray[3].getLineNumber()) + "-";
        }
        return "";
    }

    public static void consoleLoggerInit () {
        consoleLoggerInit (null);
    }

    public static void consoleLoggerInit (Level logLevel) {
        Logger root = Logger.getRootLogger();

        if (root != null) {
            root.removeAllAppenders();
            if (logLevel != null) {
                root.setLevel(logLevel);
            } else {
                root.setLevel(Level.INFO);
            }

            root.addAppender(new ConsoleAppender(
                    new PatternLayout("%5p [%t] (%c{1}) %m%n")
            ));
        }
    }
    public static String validateInput(Object msg) {
		try {
			String aString="";
			if(msg!=null)
				aString=msg.toString();
			return ESAPI.validator().getValidInput(CommonConstants.ESAPI_CONSTANTS.CONTEXT_INPUT_VALIDATION, aString, 
					CommonConstants.ESAPI_CONSTANTS.VAL_TYPE_SOMETHING_ELSE, aString.length()+1,false);
		} catch (Exception e) {
			return "";
		}
	}
}
