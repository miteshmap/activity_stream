<?php
/**
 * @file
 * Views style plugins to render nodes in the XML data format.
 *
 * @see iv_activity_stream_plugin_style_xml.inc
 * @ingroup views_plugins
 */


/**
 * Implementation of hook_views_plugin().
 */
function iv_activity_stream_views_plugins() {
  $path = drupal_get_path('module', 'iv_activity_stream'); 
	return array(
	   'module' => 'iv_activity_stream',
      'style'   => array(
        'iv_activity_stream_xml_style' => array(
          'title'           => ('Activity Streams'),
	        'path'            => $path,
          'help'            => ('Display a view as an Google news document.'),
          'handler'         => 'iv_activity_stream_plugin_style_xml',
	        'theme'           => 'iv_activity_stream_xml_style',
	        'theme file'      => 'iv_activity_stream_xml_style.theme.inc',
	        'theme path'      => $path.'/theme',
          'uses row plugin' => FALSE,
          'uses fields'     => TRUE,
          'uses options'    => TRUE,
	        'type'            => 'normal',
	        'help_topic'      => 'style-xml',
	        'even empty'      => TRUE
       ),
     ),
    );
}
