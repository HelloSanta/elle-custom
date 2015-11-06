<?php
/**
 * @file
 * company_webform.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function company_webform_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'eva_company_info';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(EVA)公司聯絡地圖資訊';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* 欄位: Content: 公司中文地址 */
  $handler->display->display_options['fields']['field_company_addr']['id'] = 'field_company_addr';
  $handler->display->display_options['fields']['field_company_addr']['table'] = 'field_data_field_company_addr';
  $handler->display->display_options['fields']['field_company_addr']['field'] = 'field_company_addr';
  $handler->display->display_options['fields']['field_company_addr']['label'] = '';
  $handler->display->display_options['fields']['field_company_addr']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_addr']['type'] = 'simple_gmap';
  $handler->display->display_options['fields']['field_company_addr']['settings'] = array(
    'include_map' => 1,
    'include_static_map' => 0,
    'iframe_width' => '',
    'iframe_height' => '',
    'include_link' => 0,
    'link_text' => 'View larger map',
    'zoom_level' => '14',
    'information_bubble' => 1,
    'include_text' => 0,
    'map_type' => 'm',
    'langcode' => 'zh-tw',
  );
  /* 欄位: Content: 公司中文名稱 */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['label'] = '';
  $handler->display->display_options['fields']['field_company_name']['element_label_colon'] = FALSE;
  /* 欄位: Content: 公司英文名稱 */
  $handler->display->display_options['fields']['field_company_eng_name']['id'] = 'field_company_eng_name';
  $handler->display->display_options['fields']['field_company_eng_name']['table'] = 'field_data_field_company_eng_name';
  $handler->display->display_options['fields']['field_company_eng_name']['field'] = 'field_company_eng_name';
  $handler->display->display_options['fields']['field_company_eng_name']['label'] = '';
  $handler->display->display_options['fields']['field_company_eng_name']['element_label_colon'] = FALSE;
  /* 欄位: Content: 公司中文地址 */
  $handler->display->display_options['fields']['field_company_addr_1']['id'] = 'field_company_addr_1';
  $handler->display->display_options['fields']['field_company_addr_1']['table'] = 'field_data_field_company_addr';
  $handler->display->display_options['fields']['field_company_addr_1']['field'] = 'field_company_addr';
  $handler->display->display_options['fields']['field_company_addr_1']['label'] = '地址';
  /* 欄位: Content: 公司英文地址 */
  $handler->display->display_options['fields']['field_company_eng_addr']['id'] = 'field_company_eng_addr';
  $handler->display->display_options['fields']['field_company_eng_addr']['table'] = 'field_data_field_company_eng_addr';
  $handler->display->display_options['fields']['field_company_eng_addr']['field'] = 'field_company_eng_addr';
  $handler->display->display_options['fields']['field_company_eng_addr']['label'] = '';
  $handler->display->display_options['fields']['field_company_eng_addr']['element_label_colon'] = FALSE;
  /* 欄位: Content: 公司電話 */
  $handler->display->display_options['fields']['field_company_phone']['id'] = 'field_company_phone';
  $handler->display->display_options['fields']['field_company_phone']['table'] = 'field_data_field_company_phone';
  $handler->display->display_options['fields']['field_company_phone']['field'] = 'field_company_phone';
  $handler->display->display_options['fields']['field_company_phone']['label'] = '電話';
  /* 欄位: Content: 公司傳真 */
  $handler->display->display_options['fields']['field_company_fax']['id'] = 'field_company_fax';
  $handler->display->display_options['fields']['field_company_fax']['table'] = 'field_data_field_company_fax';
  $handler->display->display_options['fields']['field_company_fax']['field'] = 'field_company_fax';
  $handler->display->display_options['fields']['field_company_fax']['label'] = '傳真';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company_information' => 'company_information',
  );

  /* Display: EVA Field */
  $handler = $view->new_display('entity_view', 'EVA Field', 'entity_view_1');
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'webform',
  );
  $translatables['eva_company_info'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('地址'),
    t('電話'),
    t('傳真'),
    t('EVA Field'),
  );
  $export['eva_company_info'] = $view;

  return $export;
}
