<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '1234' ); /* Change from passwd */

/** MySQL hostname */
define( 'DB_HOST', 'mysql' );#Change from localhost

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'P]9:Ry5iF[V)05!_]*R,Hjyh?3.s0f=wy|9Sp!H+ T`DecoNf%13wI{A_~sl8c*5');
define('SECURE_AUTH_KEY',  'HrgF33}K^UAAUFs`Bp&$C!jC O%_6yH%WY$y=bl%?~#4RPTbe?V=6V9wQ3wiKH]`');
define('LOGGED_IN_KEY',    'pvJ4|2TQ`6~a/q*DRZ`X[HyzR|df3C6LDzk7?Izy|UZr+ikMgpyZ#`3tE/(=^g%3');
define('NONCE_KEY',        'O6wW.w<DWlOwhP]q-HN!wN[`$_/0DK[cX1`=z3nS=dh&-.W7r@n3$V6SW_su/V+u');
define('AUTH_SALT',        '|9u{LU~>+_l~X}>nY[9d1*wA<kUYFH*]M+FV7Q|a(x3S,OoL0q|H#H=J2BS#VyHp');
define('SECURE_AUTH_SALT', '-2cO#+M_,X3!id9#FAbGF[jUj1Vwvv1H,T`?+LB@#r)30-Q*qtrciR`l<oQTkHW[');
define('LOGGED_IN_SALT',   '>PK:JvBoz$0rg(7.GG9+TXBcIvON:wM+3tdm}baBPb!sg/bLPOptd5i  x1e]mZz');
define('NONCE_SALT',       '4q,).-ca)0(pe!po*|,!u4y.fHhbjd*2NHlC7&6A6rlns8I?/CDBT]|+Xti:F0&Q');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
