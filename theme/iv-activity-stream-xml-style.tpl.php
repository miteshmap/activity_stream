<?php
// $Id: views-activity-stream-style.tpl.php
/**
 * @file views-activity-stream-style.tpl.php
 * Default template for the Views XML style plugin
 *
 * @ingroup views_templates
 */

global $base_url;

  $xml = '<?xml version="1.0" encoding="UTF-8"?>';
  $xml .= '<feed xml:lang="en-US" xmlns="http://www.w3.org/2005/Atom" xmlns:activity="http://activitystrea.ms/spec/1.0/" xmlns:thr="http://purl.org/syndication/thread/1.0" xmlns:media="http://purl.org/syndication/atommedia" xmlns:service="http://activitystrea.ms/service-provider" xmlns:echo="http://js-kit.com/spec/e2/v1">';

foreach($entries as $entry) {
	//_views_xml_debug_stop($entry);
  $xml .= "  <entry>\n";
    if($entry['acitiviy_id'])$xml .= "  <id>".$entry['acitiviy_id']."</id>\n";
    if($entry['activity_title'])$xml .= "  <title>".$entry['activity_title']."</title>\n";
    if($entry['activity_postdate'])$xml .= "  <published>".$entry['activity_postdate']."</published>\n";
    if($entry['activity_url'])$xml .= "  <link rel=\"alternate\" type=\"text/html\" href=\"".$entry['activity_url']."\" />\n";
    $xml .= "<activity:verb>http://activitystrea.ms/schema/1.0/post</activity:verb>";
    if($entry['author_name'] || $entry['author_uri'] || $entry['author_id'] || $entry['author_uri']){
      $xml .= "  <activity:actor>\n";
      if($entry['author_uri'])$xml .= "     <id>".$entry['author_uri']."</id>\n";
      if($entry['author_name'])$xml .= "     <name>".$entry['author_name']."</name>\n";
      if($entry['author_uri'])$xml .= "     <uri>".$entry['author_uri']."</uri>\n";
      $xml .= "     <activity:object-type>person</activity:object-type>\n";
      if($entry['author_uri'])$xml .= "     <link rel=\"alternate\" type=\"text/html\" href=\"".$entry['author_uri']."\" />\n";
      $xml .= "  </activity:actor>\n";
    }
    
      $xml .= "<activity:object>";
      $xml .= "<id>".$entry["object_id"]."</id>";
      $xml .= "<activity:object-type>http://activitystrea.ms/schema/1.0/comment</activity:object-type>";
    
      if(!empty($entry["object_content"])){
        $xml .= '<content type="html"><![CDATA['.addslashes($entry["object_content"]).']]</content>';
      } else{
        $xml .= '<content type="html"></content>';  
      }
      
      $xml .= "<published>".$entry["object_published"]."</published>";
      $xml .= "</activity:object>";
    
        $xml .= "  <activity:target>\n";
        $xml .= "     <id>".$entry['activity_url']."</id>\n";
        $xml .= "     <link rel=\"alternate\" type=\"text/html\" href=\"".$entry['activity_url']."\" />\n";
        $xml .= "     <activity:object-type>http://activitystrea.ms/schema/1.0/article</activity:object-type>\n";
        $xml .= "  </activity:target>\n";
      
    $xml .= "  </entry>\n";
}
  $xml .= "</feed>\n";
  
  if ($view->override_path) {       // inside live preview
    print htmlspecialchars($xml);
  }
  else {
  	drupal_set_header('Content-Type: text/xml');
    print $xml;
    exit;
  }