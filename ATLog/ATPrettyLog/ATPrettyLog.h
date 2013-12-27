//
//  ATPrettyLog.h
//  ATLog
//
//  Created by Yan Rabovik on 21.08.13.
//
//

// This will fail if ATLog.h is imported in the pch and one of the files in the project doesn't use ARC.
// ATString.m also has the check, so it should catch improper use.
//#if !__has_feature(objc_arc)
//#error This code needs ARC. Use compiler option -fobjc-arc
//#endif

#define ATPrettyLog(fmt,...) \
{ \
    NSDateFormatter *__atpl_df = [NSDateFormatter new]; \
    [__atpl_df setDateFormat:@"HH:mm:ss.SSS"]; \
    NSString *__atpl_str = \
        [NSString stringWithFormat:@"%@ %s [Line %d] " fmt, \
                                   [__atpl_df stringFromDate:[NSDate date]], \
                                   __PRETTY_FUNCTION__, \
                                   __LINE__, \
                                   ##__VA_ARGS__]; \
    fprintf(stderr,"%s\n", [__atpl_str UTF8String]); \
}