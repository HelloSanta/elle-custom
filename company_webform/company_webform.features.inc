<?php
/**
 * @file
 * company_webform.features.inc
 */

/**
 * Implements hook_views_api().
 */
function company_webform_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function company_webform_node_info() {
  $items = array(
    'company_information' => array(
      'name' => t('公司資訊'),
      'base' => 'node_content',
      'description' => t('公司資訊'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
