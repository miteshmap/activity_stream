<?php
/**
 * @file
 * Implementation of views_plugin_style for iv_activity_stream
 */


/**
 * Implementation of views_plugin_style
 */
class iv_activity_stream_plugin_style_xml extends views_plugin_style {

  /** 
   * Implementation of views_plugin_style::option_definition 
   */ 
	function option_definition() {
		global $user;
    $options = parent::option_definition();
    
    $options['acitiviy_id'] = array('default' => NULL, 'translatable' => FALSE);
    $options['activity_title'] = array('default' => NULL, 'translatable' => FALSE);
    $options['activity_postdate'] = array('default' => NULL, 'translatable' => FALSE);
    $options['activity_url'] = array('default' => NULL, 'translatable' => FALSE);
    $options['author']['author_name'] = array('default' => NULL, 'translatable' => FALSE);
    $options['author']['author_uri'] = array('default' => NULL, 'translatable' => FALSE);
    $options['author']['author_id'] = array('default' => NULL, 'translatable' => FALSE);
    $options['object']['object_id'] = array('default' => NULL, 'translatable' => FALSE);
    $options['object']['object_published'] = array('default' => NULL, 'translatable' => FALSE);
    $options['object']['object_content'] = array('default' => NULL, 'translatable' => FALSE);
    
    
    return $options;
  }
  
  /**
   * Provide a form for setting options.
   *
   * @param $form
   * @param $form_state
   */
  function options_form(&$form, &$form_state) {
    
    
    $handlers = $this->display->handler->get_handlers('field');
    if (empty($handlers)) {
      drupal_set_message(t('You need at least one field before you can configure your field settings.'), 'error');
    }
    else {
    $field_names = array('' => '--');
      foreach ($handlers as $field => $handler) {
        if ($label = $handler->label()) {
          $field_names[$field] = $label;
        }
        else {
          $field_names[$field] = $handler->ui_name();
        }
      }
    }  
    
    $form['acitiviy_id'] = array(
      '#type' => 'select',
      '#title' => t('Acitivity ID'),
      '#options' => $field_names,
      '#default_value' => $this->options['acitiviy_id'],
    );
    
  	$form['activity_title'] = array(
      '#type' => 'select',
      '#title' => t('Activity title'),
      '#options' => $field_names,
      '#default_value' => $this->options['activity_title'],
    );
           
   $form['activity_postdate']  = array(
      '#type' => 'select',
      '#title' => t('Activity Postdate'),  
      '#options' => $field_names,
      '#default_value' => $this->options['activity_postdate'],
    );
    
    $form['activity_url'] = array(
      '#type'           => 'select',
      '#title'          => ('Activity url'),
      '#options' => $field_names,
      '#default_value'  => $this->options['activity_url'],
      '#description'    => ('For each row in the view, strip all markup from the field output.'),
    );
    
    $form['author'] = array(
      '#type' => 'fieldset',
      '#title' => t('Author elements'),
      '#description' => t('Provide values for Author'),
      '#collapsible' => TRUE,
      '#collapsed' => false,
    );
    
    $form['author']['author_id'] = array(
      '#type' => 'select',
      '#title' => t('Author Id'),
      '#options' => $field_names,
      '#default_value' => $this->options['author']['author_id'],
    );
    
    $form['author']['author_name'] = array(
      '#type' => 'select',
      '#title' => t('Author Name'),
      '#options' => $field_names,
      '#default_value' => $this->options['author']['author_name'],
    );
    
    $form['author']['author_uri'] = array(
      '#type' => 'select',
      '#title' => t('Author URI'),
      '#options' => $field_names,
      '#default_value' => $this->options['author']['author_uri'],
    );
    
    $form['object'] = array(
      '#type' => 'fieldset',
      '#title' => t('Activity Object'),
      '#description' => t('Provide values for Object elements'),
      '#collapsible' => TRUE,
      '#collapsed' => false,
    );
    
    $form['object']['object_id'] = array(
      '#type' => 'select',
      '#title' => t('Object Id'),
      '#options' => $field_names,
      '#default_value' => $this->options['object']['object_id'],
    );
    
    $form['object']['object_published'] = array(
      '#type' => 'select',
      '#title' => t('Object Published'),
      '#options' => $field_names,
      '#default_value' => $this->options['object']['object_published'],
    );
    
    $form['object']['object_content'] = array(
      '#type' => 'select',
      '#title' => t('Object Content'),
      '#options' => $field_names,
      '#default_value' => $this->options['object']['object_content'],
    );
   
  } 
 	
  /**
   * Implementation of views_style_plugin::theme_functions(). Returns an array of theme functions to use.
   * for the current style plugin
   * @return array 
   */
  function theme_functions() {
    $hook = 'iv_activity_stream_xml_style'; 
  	return views_theme_functions($hook, $this->view, $this->display);
  }

/**
 * Implementation of views_style_plugin::additional_theme_functions(). Returns empty array.
 * @return array
 */  
  function additional_theme_functions() {
  	return array();
  }
  
  /**
   * Implementation of view_style_plugin::render()
   */
  function render() {
  	$view = $this->view;
  	$options = $this->options;
  	$field = $view->field;
  	
 	  $rows = array();
    
 	  foreach ($view->result as $row) {
      $rows[] = _iv_activity_stream_render_fields($view, $row);        
    }
    
    return theme($this->theme_functions(), $this->view, $this->options, $rows);    	  
 	}
 
}