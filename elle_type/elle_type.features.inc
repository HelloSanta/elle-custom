<?php
/**
 * @file
 * elle_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function elle_type_node_info() {
  $items = array(
    'article' => array(
      'name' => t('New Dossier'),
      'base' => 'node_content',
      'description' => t('New Dossier and Gallery 文章在此建立'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
    'editor' => array(
      'name' => t('特約編輯'),
      'base' => 'node_content',
      'description' => t('特約編輯個人資料上架處'),
      'has_title' => '1',
      'title_label' => t('編輯名稱'),
      'help' => '',
    ),
    'elle_shopping' => array(
      'name' => t('ELLE SHOPPING'),
      'base' => 'node_content',
      'description' => t('上傳產品圖片與要連結到的產品外部連結'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
    'elle_tv' => array(
      'name' => t('ELLE TV'),
      'base' => 'node_content',
      'description' => t('所有ELLE TV文章都在此上架'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
    'fad' => array(
      'name' => t('FAD'),
      'base' => 'node_content',
      'description' => t('上傳首頁與收錄頁面的slideshow，可以選擇連結為外部或內部連結'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
    'free_article' => array(
      'name' => t('Free Article'),
      'base' => 'node_content',
      'description' => t('Free Article文章在此建立'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
    'main_ad_content' => array(
      'name' => t('首頁廣告'),
      'base' => 'node_content',
      'description' => t('首頁廣告特區，只有三個版位。純粹上標題、圖片、連結'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
    'nodeblock' => array(
      'name' => t('廣告區塊'),
      'base' => 'node_content',
      'description' => t('各個收錄頁面廣告區塊'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
    'static_page' => array(
      'name' => t('靜態頁面'),
      'base' => 'node_content',
      'description' => t('所有單一靜態頁面文章在這裏產生。例如：隱私權條款、免責條款'),
      'has_title' => '1',
      'title_label' => t('標題'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
