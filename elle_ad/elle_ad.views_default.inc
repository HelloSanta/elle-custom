<?php
/**
 * @file
 * elle_ad.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function elle_ad_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ad_article_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(AD)文章廣告';
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
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重設';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['arguments']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['arguments']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['arguments']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['arguments']['field_ad_position_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_ad_position_target_id']['exception']['title'] = '所有';
  $handler->display->display_options['arguments']['field_ad_position_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_ad_position_target_id']['default_argument_options']['code'] = '$nid=arg(1);
$node=node_load($nid);
$tid=$node->field_folder_taxonomy[\'und\'][0][\'target_id\'];
$parent= taxonomy_get_parents($tid);
if(empty($parent)){
	return $tid;
}
else{
	foreach($parent as $key => $value){
		$tid=$value->tid;
	}
	return $tid;
}

';
  $handler->display->display_options['arguments']['field_ad_position_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ad_position_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ad_position_target_id']['summary_options']['items_per_page'] = '25';
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
    'nodeblock' => 'nodeblock',
  );

  /* Display: 右側廣告1 */
  $handler = $view->new_display('block', '右側廣告1', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'article-1' => 'article-1',
  );

  /* Display: 右側廣告2 */
  $handler = $view->new_display('block', '右側廣告2', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'article-2' => 'article-2',
  );

  /* Display: 橫向廣告1 */
  $handler = $view->new_display('block', '橫向廣告1', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'aritlce-3' => 'aritlce-3',
  );

  /* Display: 橫向廣告2 */
  $handler = $view->new_display('block', '橫向廣告2', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'aritlce-4' => 'aritlce-4',
  );

  /* Display: 文章進站前 */
  $handler = $view->new_display('block', '文章進站前', 'block_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'before-access' => 'before-access',
  );

  /* Display: 文章320x50 */
  $handler = $view->new_display('block', '文章320x50', 'block_5');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '320x50' => '320x50',
  );

  /* Display: 文章320x480 */
  $handler = $view->new_display('block', '文章320x480', 'block_6');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '320x480' => '320x480',
  );
  $translatables['ad_article_block'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('重設'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('所有'),
    t('右側廣告1'),
    t('右側廣告2'),
    t('橫向廣告1'),
    t('橫向廣告2'),
    t('文章進站前'),
    t('文章320x50'),
    t('文章320x480'),
  );
  $export['ad_article_block'] = $view;

  $view = new view();
  $view->name = 'ad_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(AD)收錄廣告區塊';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );

  /* Display: 首頁Header廣告 */
  $handler = $view->new_display('block', '首頁Header廣告', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '526';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'header-ad1' => 'header-ad1',
  );

  /* Display: 首頁側邊欄1 */
  $handler = $view->new_display('block', '首頁側邊欄1', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '526';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side1' => 'right-side1',
  );

  /* Display: 首頁橫向廣告1 */
  $handler = $view->new_display('block', '首頁橫向廣告1', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '526';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'hr-ad1' => 'hr-ad1',
  );

  /* Display: 首頁橫向廣告2 */
  $handler = $view->new_display('block', '首頁橫向廣告2', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '526';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'hr-ad2' => 'hr-ad2',
  );

  /* Display: DECOR右側1 */
  $handler = $view->new_display('block', 'DECOR右側1', 'block_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '17';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side1' => 'right-side1',
  );

  /* Display: DECOR右側2 */
  $handler = $view->new_display('block', 'DECOR右側2', 'block_5');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '17';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side2' => 'right-side2',
  );

  /* Display: DECOR右側3 */
  $handler = $view->new_display('block', 'DECOR右側3', 'block_6');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '17';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side3' => 'right-side3',
  );

  /* Display: DECOR橫向1 */
  $handler = $view->new_display('block', 'DECOR橫向1', 'block_7');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '17';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'hr-ad1' => 'hr-ad1',
  );

  /* Display: DECOR進站前 */
  $handler = $view->new_display('block', 'DECOR進站前', 'block_31');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '17';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'before-access' => 'before-access',
  );

  /* Display: GIRL右側1 */
  $handler = $view->new_display('block', 'GIRL右側1', 'block_8');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '16';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side1' => 'right-side1',
  );

  /* Display: GIRL右側2 */
  $handler = $view->new_display('block', 'GIRL右側2', 'block_9');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '16';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side2' => 'right-side2',
  );

  /* Display: GIRL右側3 */
  $handler = $view->new_display('block', 'GIRL右側3', 'block_10');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '16';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side3' => 'right-side3',
  );

  /* Display: GIRL橫向1 */
  $handler = $view->new_display('block', 'GIRL橫向1', 'block_11');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '16';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'hr-ad1' => 'hr-ad1',
  );

  /* Display: GIRL進站前 */
  $handler = $view->new_display('block', 'GIRL進站前', 'block_30');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '16';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'before-access' => 'before-access',
  );

  /* Display: WEDDING右側1 */
  $handler = $view->new_display('block', 'WEDDING右側1', 'block_12');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '28';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side1' => 'right-side1',
  );

  /* Display: WEDDING右側2 */
  $handler = $view->new_display('block', 'WEDDING右側2', 'block_13');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '28';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side2' => 'right-side2',
  );

  /* Display: WEDDING右側3 */
  $handler = $view->new_display('block', 'WEDDING右側3', 'block_14');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '28';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side3' => 'right-side3',
  );

  /* Display: WEDDING橫向1 */
  $handler = $view->new_display('block', 'WEDDING橫向1', 'block_15');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '28';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'hr-ad1' => 'hr-ad1',
  );

  /* Display: WEDDING進站前 */
  $handler = $view->new_display('block', 'WEDDING進站前', 'block_32');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '28';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'before-access' => 'before-access',
  );

  /* Display: ACCESSORY右側1 */
  $handler = $view->new_display('block', 'ACCESSORY右側1', 'block_16');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '29';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side1' => 'right-side1',
  );

  /* Display: ACCESSORY右側2 */
  $handler = $view->new_display('block', 'ACCESSORY右側2', 'block_17');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '29';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side2' => 'right-side2',
  );

  /* Display: ACCESSORY右側3 */
  $handler = $view->new_display('block', 'ACCESSORY右側3', 'block_18');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '29';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side3' => 'right-side3',
  );

  /* Display: ACCESSORY橫向1 */
  $handler = $view->new_display('block', 'ACCESSORY橫向1', 'block_19');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '29';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'hr-ad1' => 'hr-ad1',
  );

  /* Display: ACCESSORY進站前 */
  $handler = $view->new_display('block', 'ACCESSORY進站前', 'block_29');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '29';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'before-access' => 'before-access',
  );

  /* Display: TV右側1 */
  $handler = $view->new_display('block', 'TV右側1', 'block_20');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '530';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side1' => 'right-side1',
  );

  /* Display: TV右側2 */
  $handler = $view->new_display('block', 'TV右側2', 'block_21');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '530';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side2' => 'right-side2',
  );

  /* Display: 專欄作家橫向1 */
  $handler = $view->new_display('block', '專欄作家橫向1', 'block_22');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '525';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'hr-ad1' => 'hr-ad1',
  );

  /* Display: 專欄作家橫向2 */
  $handler = $view->new_display('block', '專欄作家橫向2', 'block_23');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '525';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'hr-ad2' => 'hr-ad2',
  );

  /* Display: 專欄作家右側1 */
  $handler = $view->new_display('block', '專欄作家右側1', 'block_24');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '525';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side1' => 'right-side1',
  );

  /* Display: 專欄作家右側2 */
  $handler = $view->new_display('block', '專欄作家右側2', 'block_25');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '525';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side2' => 'right-side2',
  );

  /* Display: 線上活動右側1 */
  $handler = $view->new_display('block', '線上活動右側1', 'block_26');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '79';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side1' => 'right-side1',
  );

  /* Display: 線上活動文章右側1 */
  $handler = $view->new_display('block', '線上活動文章右側1', 'block_27');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '79';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'article-1' => 'article-1',
  );

  /* Display: 線上活動文章右側2 */
  $handler = $view->new_display('block', '線上活動文章右側2', 'block_28');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '79';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'article-2' => 'article-2',
  );

  /* Display: 專欄作家進站前 */
  $handler = $view->new_display('block', '專欄作家進站前', 'block_33');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '525';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'before-access' => 'before-access',
  );
  $translatables['ad_block'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('首頁Header廣告'),
    t('首頁側邊欄1'),
    t('首頁橫向廣告1'),
    t('首頁橫向廣告2'),
    t('DECOR右側1'),
    t('DECOR右側2'),
    t('DECOR右側3'),
    t('DECOR橫向1'),
    t('DECOR進站前'),
    t('GIRL右側1'),
    t('GIRL右側2'),
    t('GIRL右側3'),
    t('GIRL橫向1'),
    t('GIRL進站前'),
    t('WEDDING右側1'),
    t('WEDDING右側2'),
    t('WEDDING右側3'),
    t('WEDDING橫向1'),
    t('WEDDING進站前'),
    t('ACCESSORY右側1'),
    t('ACCESSORY右側2'),
    t('ACCESSORY右側3'),
    t('ACCESSORY橫向1'),
    t('ACCESSORY進站前'),
    t('TV右側1'),
    t('TV右側2'),
    t('專欄作家橫向1'),
    t('專欄作家橫向2'),
    t('專欄作家右側1'),
    t('專欄作家右側2'),
    t('線上活動右側1'),
    t('線上活動文章右側1'),
    t('線上活動文章右側2'),
    t('專欄作家進站前'),
  );
  $export['ad_block'] = $view;

  $view = new view();
  $view->name = 'ad_folder_banner';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = '(AD)頻道廣告';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_ad_position_node']['id'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['relationships']['reverse_field_ad_position_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_ad_position_node']['field'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['relationships']['reverse_field_ad_position_node']['label'] = '內容 referencing 分類項目 from field_ad_position';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = '所有';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = '$tid=arg(2);
$parent= taxonomy_get_parents($tid);
if(empty($parent)){
	return $tid;
}
else{
	foreach($parent as $key => $value){
		$tid=$value->tid;
	}
	return $tid;
}
';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );

  /* Display: 頻道廣告Banner */
  $handler = $view->new_display('block', '頻道廣告Banner', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'banner-ad1' => 'banner-ad1',
  );

  /* Display: 頻道橫向廣告 */
  $handler = $view->new_display('block', '頻道橫向廣告', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'hr-ad1' => 'hr-ad1',
  );

  /* Display: 頻道右側廣告1 */
  $handler = $view->new_display('block', '頻道右側廣告1', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side1' => 'right-side1',
  );

  /* Display: 頻道右側廣告2 */
  $handler = $view->new_display('block', '頻道右側廣告2', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'right-side2' => 'right-side2',
  );

  /* Display: 頻道橫向廣告2 */
  $handler = $view->new_display('block', '頻道橫向廣告2', 'block_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'hr-ad2' => 'hr-ad2',
  );

  /* Display: 頻道進站前 */
  $handler = $view->new_display('block', '頻道進站前', 'block_5');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'before-access' => 'before-access',
  );

  /* Display: 頻道2000X1200 */
  $handler = $view->new_display('block', '頻道2000X1200', 'block_6');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '2000X1200' => '2000X1200',
  );

  /* Display: 頻道1000X300 */
  $handler = $view->new_display('block', '頻道1000X300', 'block_7');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '1000X300' => '1000X300',
  );

  /* Display: 頻道1000x600 */
  $handler = $view->new_display('block', '頻道1000x600', 'block_8');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '1000x600' => '1000x600',
  );

  /* Display: 頻道320x480 */
  $handler = $view->new_display('block', '頻道320x480', 'block_9');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '320x480' => '320x480',
  );

  /* Display: 頻道320x50 */
  $handler = $view->new_display('block', '頻道320x50', 'block_10');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '320x50' => '320x50',
  );

  /* Display: 頻道640x100 */
  $handler = $view->new_display('block', '頻道640x100', 'block_11');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'folder_taxonomy' => 'folder_taxonomy',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['relationship'] = 'reverse_field_ad_position_node';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '640x100' => '640x100',
  );
  $translatables['ad_folder_banner'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('內容 referencing 分類項目 from field_ad_position'),
    t('所有'),
    t('頻道廣告Banner'),
    t('頻道橫向廣告'),
    t('頻道右側廣告1'),
    t('頻道右側廣告2'),
    t('頻道橫向廣告2'),
    t('頻道進站前'),
    t('頻道2000X1200'),
    t('頻道1000X300'),
    t('頻道1000x600'),
    t('頻道320x480'),
    t('頻道320x50'),
    t('頻道640x100'),
  );
  $export['ad_folder_banner'] = $view;

  $view = new view();
  $view->name = 'ad_special';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = '(AD)特別廣告';
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
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重設';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '526';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'before-access' => 'before-access',
  );

  /* Display: 首頁進站前 */
  $handler = $view->new_display('block', '首頁進站前', 'block');

  /* Display: 首頁2000X1200 */
  $handler = $view->new_display('block', '首頁2000X1200', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '526';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '2000X1200' => '2000X1200',
  );

  /* Display: 首頁1000X300 */
  $handler = $view->new_display('block', '首頁1000X300', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '526';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '1000X300' => '1000X300',
  );

  /* Display: 首頁1000x600 */
  $handler = $view->new_display('block', '首頁1000x600', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '526';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '1000x600' => '1000x600',
  );

  /* Display: 首頁320x480 */
  $handler = $view->new_display('block', '首頁320x480', 'block_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '526';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '320x480' => '320x480',
  );

  /* Display: 首頁320x50 */
  $handler = $view->new_display('block', '首頁320x50', 'block_5');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '526';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    '320x50' => '320x50',
  );

  /* Display: 登入註冊頁廣告 */
  $handler = $view->new_display('block', '登入註冊頁廣告', 'block_6');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'nodeblock' => 'nodeblock',
  );
  /* Filter criterion: Content: 發佈頁面 (field_ad_position) */
  $handler->display->display_options['filters']['field_ad_position_target_id']['id'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['table'] = 'field_data_field_ad_position';
  $handler->display->display_options['filters']['field_ad_position_target_id']['field'] = 'field_ad_position_target_id';
  $handler->display->display_options['filters']['field_ad_position_target_id']['value']['value'] = '11416';
  /* Filter criterion: Content: Location (field_ad_number) */
  $handler->display->display_options['filters']['field_ad_number_value']['id'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['table'] = 'field_data_field_ad_number';
  $handler->display->display_options['filters']['field_ad_number_value']['field'] = 'field_ad_number_value';
  $handler->display->display_options['filters']['field_ad_number_value']['value'] = array(
    'article-5' => 'article-5',
  );
  $translatables['ad_special'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('重設'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('首頁進站前'),
    t('首頁2000X1200'),
    t('首頁1000X300'),
    t('首頁1000x600'),
    t('首頁320x480'),
    t('首頁320x50'),
    t('登入註冊頁廣告'),
  );
  $export['ad_special'] = $view;

  return $export;
}
