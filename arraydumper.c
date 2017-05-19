/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_arraydumper.h"

/* If you declare any globals in php_arraydumper.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(arraydumper)
*/

/* True global resources - no need for thread safety here */
static int le_arraydumper;

#define Z_IS_PACKED_ARRAY(zp) _z_is_packed_array(zp)

static inline int _z_is_packed_array(zval *zp)
{
	if (Z_TYPE_P(zp) != IS_ARRAY) {
		return 0;
	}
	if (HT_IS_PACKED(Z_ARR_P(zp))) {
		return 1;
	}
	return 0;
}


/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("arraydumper.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_arraydumper_globals, arraydumper_globals)
    STD_PHP_INI_ENTRY("arraydumper.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_arraydumper_globals, arraydumper_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ proto bool is_packed_array(mixed var) */
PHP_FUNCTION(is_packed_array)
{
	zval *var;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &var) == FAILURE) {
		RETURN_FALSE;
	}
	if (Z_IS_PACKED_ARRAY(var)) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
}
/* }}} */


/* {{{ php_arraydumper_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_arraydumper_init_globals(zend_arraydumper_globals *arraydumper_globals)
{
	arraydumper_globals->global_value = 0;
	arraydumper_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(arraydumper)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(arraydumper)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(arraydumper)
{
#if defined(COMPILE_DL_ARRAYDUMPER) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(arraydumper)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(arraydumper)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "arraydumper support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ arraydumper_functions[]
 *
 * Every user visible function must have an entry in arraydumper_functions[].
 */
const zend_function_entry arraydumper_functions[] = {
	PHP_FE(is_packed_array,	NULL)
	PHP_FE_END	/* Must be the last line in arraydumper_functions[] */
};
/* }}} */

/* {{{ arraydumper_module_entry
 */
zend_module_entry arraydumper_module_entry = {
	STANDARD_MODULE_HEADER,
	"arraydumper",
	arraydumper_functions,
	PHP_MINIT(arraydumper),
	PHP_MSHUTDOWN(arraydumper),
	PHP_RINIT(arraydumper),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(arraydumper),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(arraydumper),
	PHP_ARRAYDUMPER_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ARRAYDUMPER
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(arraydumper)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
