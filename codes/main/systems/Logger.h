/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LOGGER_H
#define _LOGGER_H

class Logger {
public: 
    
/**
 * @param file
 */
void Logger(File file);
    
/**
 * @param file
 */
void Logger(String file);
    
void ~Logger();
    
/**
 * @param num
 */
void debug(int num);
    
/**
 * @param str
 */
void debug(String str);
    
/**
 * @param flag
 */
void debug(bool flag);
    
/**
 * @param num
 */
void infomation(int num);
    
/**
 * @param str
 */
void infomation(String str);
    
/**
 * @param flag
 */
void infomation(bool flag);
    
/**
 * @param num
 */
void warning(int num);
    
/**
 * @param str
 */
void warning(String str);
    
/**
 * @param flag
 */
void warning(bool flag);
    
/**
 * @param num
 */
void severe(int num);
    
/**
 * @param str
 */
void severe(String str);
    
/**
 * @param flag
 */
void severe(bool flag);
    
File getFile();
    
String getAbsolutionPath();
private: 
    File file;
};

#endif //_LOGGER_H