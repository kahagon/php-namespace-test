/*
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.0 of the PHP license,       |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_0.txt.                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Keng-ichi Ahagon <k.ahagon@n-3.so>                          |
   +----------------------------------------------------------------------+
*/

/* $ Id: $ */ 

#include "php_NSTest.h"

#if HAVE_NSTEST

/* {{{ Class definitions */

/* {{{ Class NSTest */

static zend_class_entry * NSTest_ce_ptr = NULL;

/* {{{ Methods */


/* {{{ proto void foo()
   */
PHP_METHOD(NSTest, foo)
{
	zend_class_entry * _this_ce;

	zval * _this_zval = NULL;



	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "O", &_this_zval, NSTest_ce_ptr) == FAILURE) {
		return;
	}

	_this_ce = Z_OBJCE_P(_this_zval);


    php_printf("foo\n");

}
/* }}} foo */



/* {{{ proto void bar()
   */
PHP_METHOD(NSTest, bar)
{
	zend_class_entry * _this_ce;

	zval * _this_zval = NULL;



	if (zend_parse_method_parameters(ZEND_NUM_ARGS() TSRMLS_CC, getThis(), "O", &_this_zval, NSTest_ce_ptr) == FAILURE) {
		return;
	}

	_this_ce = Z_OBJCE_P(_this_zval);


    php_printf("bar\n");

}
/* }}} bar */


static zend_function_entry NSTest_methods[] = {
	PHP_ME(NSTest, foo, NULL, /**/ZEND_ACC_PUBLIC)
	PHP_ME(NSTest, bar, NULL, /**/ZEND_ACC_PUBLIC)
	{ NULL, NULL, NULL }
};

/* }}} Methods */

static void class_init_NSTest(void)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "PHPMake\\NSTest", NSTest_methods);
	NSTest_ce_ptr = zend_register_internal_class(&ce);
}

/* }}} Class NSTest */

/* }}} Class definitions*/

/* {{{ NSTest_functions[] */
function_entry NSTest_functions[] = {
	ZEND_NS_FE("PHPMake", baz                 , baz_arg_info)
	{ NULL, NULL, NULL }
};
/* }}} */


/* {{{ NSTest_module_entry
 */
zend_module_entry NSTest_module_entry = {
	STANDARD_MODULE_HEADER,
	"NSTest",
	NSTest_functions,
	PHP_MINIT(NSTest),     /* Replace with NULL if there is nothing to do at php startup   */ 
	PHP_MSHUTDOWN(NSTest), /* Replace with NULL if there is nothing to do at php shutdown  */
	PHP_RINIT(NSTest),     /* Replace with NULL if there is nothing to do at request start */
	PHP_RSHUTDOWN(NSTest), /* Replace with NULL if there is nothing to do at request end   */
	PHP_MINFO(NSTest),
	PHP_NSTEST_VERSION, 
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_NSTEST
ZEND_GET_MODULE(NSTest)
#endif


/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(NSTest)
{
	REGISTER_STRINGL_CONSTANT("GORILLA_VERSION", "PHP_GORILLA_VERSION", 19, CONST_PERSISTENT | CONST_CS);
	class_init_NSTest();

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(NSTest)
{

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(NSTest)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RSHUTDOWN_FUNCTION */
PHP_RSHUTDOWN_FUNCTION(NSTest)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(NSTest)
{
	php_printf("API for talking to serialport\n");
	php_info_print_table_start();
	php_info_print_table_row(2, "Version",PHP_NSTEST_VERSION " (alpha)");
	php_info_print_table_row(2, "Released", "2012-12-09");
	php_info_print_table_row(2, "CVS Revision", "$Id: $");
	php_info_print_table_row(2, "Authors", "Keng-ichi Ahagon 'k.ahagon@n-3.so' (lead)\n");
	php_info_print_table_end();
	/* add your stuff here */

}
/* }}} */

/* {{{ proto void baz()
   */
PHP_FUNCTION(baz)
{



	if (ZEND_NUM_ARGS()>0)  {
		WRONG_PARAM_COUNT;
	}


    php_printf("baz\n");

}

#endif /* HAVE_NSTEST */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
