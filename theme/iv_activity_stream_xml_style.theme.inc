<?php
/**
 * @file
 * View template to render view fields as XML.
 *
 * - $view: The view in use.
 * - $rows: Array of row objects as rendered by _views_json_render_fields 
 * - $attachment: not used currently
 * - $options: The options for the style passed in from the UI.
 *
 * @ingroup views_templates
 * @see iv_activity_stream.views.inc
 */


function template_preprocess_iv_activity_stream_xml_style($vars) {
 
  global $user;
	global $base_url; 
  $view = $vars["view"];
  $rows = $vars["rows"];
  $options = $vars["options"];
  $link = $view->display_handler->get_path();
  $url_options = array('absolute' => TRUE);
  if (!empty($view->exposed_raw_input)) {
    $url_options['query'] = $view->exposed_raw_input;
  }
	$base = $view->base_table;
  
	$entries = array();
  foreach($rows as $row) {
  	$entry = array();
    
    
    //watchdog('entries','<pre>'.print_r($row,true));
    
    if (array_key_exists($options['acitiviy_id'], $row)) {
      if($row[$options['acitiviy_id']]->raw){
        $entry["acitiviy_id"] = check_plain($row[$options['acitiviy_id']]->raw);  
      }else{
        $entry["acitiviy_id"] = check_plain($row[$options['acitiviy_id']]->content);
      }
  	} 
    
    if (array_key_exists($options['activity_title'], $row)) {
      if($row[$options['activity_title']]->raw){
        $entry["activity_title"] =check_plain($row[$options['activity_title']]->raw);  
      }else{
        $entry["activity_title"] =check_plain($row[$options['activity_title']]->content);
      }
  	}
    
    if (array_key_exists($options['activity_postdate'], $row)) {
      if($row[$options['activity_postdate']]->raw){
        $entry["activity_postdate"] = date('Y-m-d\Th:i:s\Z',$row[$options['activity_postdate']]->raw);  
      }else{
        $entry["activity_postdate"] = date('Y-m-d\Th:i:s\Z',$row[$options['activity_postdate']]->content);
      }	  	
  	}
    
    if (array_key_exists($options['activity_url'], $row)) {
      if($row[$options['activity_url']]->raw){
	  	  $entry["activity_url"] = check_plain($row[$options['activity_url']]->raw);
      }else{
        $entry["activity_url"] = check_plain($row[$options['activity_url']]->content);
      }
  	}
    
    if (array_key_exists($options['author']['author_id'], $row)) {
      if($row[$options['author_id']]->raw){
	  	  $entry["author_id"] = check_plain($row[$options['author']['author_id']]->raw);
      }else{
        $entry["author_id"] = check_plain($row[$options['author']['author_id']]->content);
      }
  	}  
    
    if (array_key_exists($options['author']['author_name'], $row)) {
      if($row[$options['author']['author_name']]->raw){
        $entry["author_name"] = check_plain($row[$options['author']['author_name']]->raw);  
      }else{
        $entry["author_name"] = check_plain($row[$options['author']['author_name']]->content);
      }	
  	}

    if (array_key_exists($options['author']['author_uri'], $row)) {
      if($row[$options['author']['author_uri']]->raw){
        $entry["author_uri"] = check_plain($row[$options['author']['author_uri']]->raw);  
      }else{
        $entry["author_uri"] = _iv_activity_stream_get_anchor_url($row[$options['author']['author_uri']]->content);
      }
	  	
  	}
    
    if (array_key_exists($options['object']['object_id'], $row)) {
        $entry["object_id"] = _iv_activity_stream_get_anchor_url($row[$options['object']['object_id']]->content);
  	}
    
    if (array_key_exists($options['object']['object_published'], $row)) {
      if($row[$options['object']['object_published']]->raw){
	  	  $entry["object_published"] = date('Y-m-d\Th:i:s\Z',$row[$options['target']['object_published']]->raw);
      }else{
        $entry["object_published"] = date('Y-m-d\Th:i:s\Z',strtotime($row[$options['target']['object_published']]->content));
      }
  	}
    
    if (array_key_exists($options['object']['object_content'], $row)) {
      if($row[$options['object']['object_content']]->raw){
	  	  $entry["object_content"] = addslashes(strip_tags($row[$options['target']['object_content']]->raw));
      }else{
        $entry["object_content"] = addslashes(strip_tags($row[$options['target']['object_content']]->content));
      }
  	}
    
    
	  $entries[] = $entry;
    
  }
 
  $vars["entries"] = $entries;  
}